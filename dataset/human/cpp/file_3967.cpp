#include <bits/stdc++.h>
using namespace std;

struct Benri { Benri() { std::cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(12);}} benri;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vll = vector<long long>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
using Real = double;
using Point = complex< Real >;

template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define F first
#define S second

template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
//constexpr int INF = 1001001001;
//constexpr ll INF = 1001001001001001001LL;
constexpr double INF = 1e10;
constexpr Real EPS = 1e-10;
const Real PI = acos(-1);
using number = double;


struct edge {
    int to; number cost;
    edge(int a, number b) : to(a), cost(b) {}
};
using wgraph = vector<vector<edge>>;

vector<number> dijkstra(int s, int V, const wgraph &G) {
    minPQ<pair<number, int>> q;
    vector<number> dist(V, INF);
    dist[s] = 0;
    q.push(mp(0, s));

    while (!q.empty()) {
        auto p = q.top(); q.pop();
        int v = p.second;
        if (dist[v] > p.first) continue;
        for (auto e : G[v]) {
            if (dist[e.to] > dist[v] + e.cost) {
                dist[e.to] = dist[v] + e.cost;
                q.push(mp(dist[e.to], e.to));
            }
        }
    }
    return dist;
}

inline double ABS(double x, double y) {
    return sqrt(x * x + y * y);
}


int main() {
    double xs, ys, xt, yt; cin >> xs >> ys >> xt >> yt;
    int n; cin >> n;

    vector<double> x(n + 2), y(n + 2), r(n + 2);
    rep(i, n) cin >> x[i + 1] >> y[i + 1] >> r[i + 1];
    x[0] = xs; y[0] = ys; r[0] = 0;
    x[n + 1] = xt; y[n + 1] = yt; r[n + 1] = 0;

    wgraph G(n + 2);
    for (int i = 0; i < n + 1; i++) {
        for (int j = i + 1; j < n + 2; j++) {
            double d = max((double)0, ABS(x[i] - x[j], y[i] - y[j]) - r[i] - r[j]);
            G[i].pb(edge(j, d));
            G[j].pb(edge(i, d));
        }
    }

    auto dist = dijkstra(0, n + 2, G);

    cout << dist[n+1] << endl;

}
