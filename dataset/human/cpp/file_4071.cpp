#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;
using vld = vector<ld>;
using vvld = vector<vld>;

typedef pair<ll, ll> P;

#define bit(n) (1LL << (n))

//#define int long long

#define all(v) v.begin(), v.end()

#define rep(i, n) for (ll i = 0; i < n; i++)
#define REP(i, n) for (ll i = 1; i < n; i++)

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORm(i, m) for (auto i = m.begin(); i != m.end(); i++)

template <class T>
inline void chmax(T& a, T b) {
  a = std::max(a, b);
}
template <class T>
inline void chmin(T& a, T b) {
  a = std::min(a, b);
}

#define mod (ll)(1e9 + 7)
// #define mod (998244353ll)

const long long INF = 1LL << 60;

// const long long INF = 1LL << 60;

template <typename T>
struct Edge {
  int to;
  T cost;
};

// Dijkstra
template <typename T>
class Dijkstra {
 private:
  vector<vector<Edge<T>>> G;
  int num_v;

 public:
  Dijkstra(int num_v) : G(num_v), num_v(num_v) {
  }

  void add_edge(int from, int to, T cost) {
    G[from].push_back((Edge<T>){to, cost});
  }

  // start: Start point
  // result: result
  void solve(int start, vector<T>& result) {
    vector<int> tmp;
    solve(start, result, tmp);
  }

  void solve(int start, vector<T>& result, vector<int>& prev) {
    result.resize(num_v, INF);
    prev.resize(num_v, -1);

    // get<0>(T): cost
    // get<1>(T): index
    // get<2>(T): ... ( for extent)
    using Tup = tuple<T, int>;
    priority_queue<Tup, vector<Tup>, greater<Tup>> que;

    que.emplace(0, start);
    result[start] = 0;

    while (!que.empty()) {
      Tup p = que.top();
      que.pop();

      T t = get<0>(p);
      int v = get<1>(p);

      // queueに入れてから別の最短経路が見つかった場合、探索処理は不要
      if (result[v] != t) {
        continue;
      }

      // vの各辺に対しよりコストの低い経路があるかを確認
      for (auto& e : G[v]) {
        if (result[e.to] > result[v] + e.cost) {
          prev[e.to] = v;
          result[e.to] = result[v] + e.cost;
          que.emplace(result[v] + e.cost, e.to);
        }
      }
    }
  }

  // t: 目的地
  vector<int> get_path(const vector<int>& prev, int t) {
    vector<int> path;

    for (int v = t; v != -1; v = prev[v]) {
      path.push_back(v);
    }

    reverse(path.begin(), path.end());
    return path;
  }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  using T = tuple<ld, ld, ld>;
  vector<T> p;

  ld sx, sy, gx, gy;
  cin >> sx >> sy >> gx >> gy;
  p.emplace_back(sx, sy, 0);
  p.emplace_back(gx, gy, 0);

  ll n;
  cin >> n;

  rep(i, n) {
    ll x, y, r;
    cin >> x >> y >> r;
    p.emplace_back(x, y, r);
  }

  Dijkstra<ld> g(n + 2);
  rep(i, p.size()) {
    rep(j, i) {
      ld dx = get<0>(p[i]) - get<0>(p[j]);
      ld dy = get<1>(p[i]) - get<1>(p[j]);
      ld c = sqrt(dx * dx + dy * dy);
      c -= get<2>(p[i]) + get<2>(p[j]);
      chmax(c, (ld)0);

      g.add_edge(i, j, c);
      g.add_edge(j, i, c);
    }
  }

  vld res;
  g.solve(0, res);

  cout << res[1] << endl;

  return 0;
}
