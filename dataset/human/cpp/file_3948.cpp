#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
//constexpr ll MOD = 998244353;
//constexpr ll MOD = ;
ll mod(ll A, ll M) {return (A % M + M) % M;}
constexpr ll INF = 1LL << 60;
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
ll divceil(ll A, ll B) {return (A + (B - 1)) / B;}
#define FINALANS(A) do {cout << (A) << '\n'; exit(0);} while (false)

using ld = long double;

struct edge
{
  ll to;
  ld cost;
  edge(ll to, ld cost) : to(to), cost(cost) {}

  bool operator<(const edge& right) const
  {
    return (cost == right.cost) ? (to < right.to) : (cost < right.cost);
  }

  bool operator>(const edge& right) const
  {
    return (cost == right.cost) ? (to > right.to) : (cost > right.cost);
  }
};

ld d(ll x0, ll y0, ll r0, ll x1, ll y1, ll r1)
{
  return max(0.0L, sqrtl((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0)) - r0 - r1);
}

int main()
{
  ll xs, ys, xt, yt;
  cin >> xs >> ys >> xt >> yt;
  ll N;
  cin >> N;
  vector<ll> X(N), Y(N), R(N);
  for (ll i = 0; i < N; i++)
  {
    cin >> X.at(i) >> Y.at(i) >> R.at(i);
  }
  X.push_back(xs), Y.push_back(ys), R.push_back(0);
  X.push_back(xt), Y.push_back(yt), R.push_back(0);

  vector<vector<edge>> G(N + 2);
  for (ll i = 0; i < N + 2; i++)
  {
    for (ll j = i + 1; j < N + 2; j++)
    {
      ld d0 = d(X.at(i), Y.at(i), R.at(i), X.at(j), Y.at(j), R.at(j));
      G.at(i).push_back(edge(j, d0));
      G.at(j).push_back(edge(i, d0));
    }
  }

  using pdl = pair<ld, ll>;

  vector<ld> dist(N + 2, -1);
  priority_queue<pdl, vector<pdl>, greater<pdl>> que;
  que.push(make_pair(0, N));

  while (!que.empty())
  {
    auto p = que.top();
    que.pop();
    ld d = p.first;
    ll v = p.second;

    if (dist.at(v) != -1)
      continue;
    dist.at(v) = d;

    for (auto e : G.at(v))
    {
      if (dist.at(e.to) == -1)
        que.push(make_pair(d + e.cost, e.to));
    }
  }

  cout << fixed << setprecision(15) << dist.at(N + 1) << endl;
}
