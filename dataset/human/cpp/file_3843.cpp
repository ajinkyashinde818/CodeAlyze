#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 1e3 + 5;

vector < vector < ll > > g (N, vector < ll > (3));
vector < vector < pair < ll, long double > > > adj (N);
vector < long double > d (N, 1e17);

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  cout << fixed << setprecision (15);

  ll xs, ys, xt, yt;
  cin >> xs >> ys >> xt >> yt;
  ll n;
  cin >> n;
  g[1] = {xs, ys, 0};
  for (int i = 2; i <= n + 1; i++) cin >> g[i][0] >> g[i][1] >> g[i][2];
  g[n + 2] = {xt, yt, 0};
  n += 2;

  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      long double dis = max (sqrt ((g[j][0] - g[i][0]) * (g[j][0] - g[i][0]) + (g[j][1] - g[i][1]) * (g[j][1] - g[i][1])) - (g[i][2] + g[j][2]), (double)0);
      adj[i].push_back({j, dis});
      adj[j].push_back({i, dis});
    }
  }

  d[1] = 0;
  priority_queue < pair < long double, int >, vector < pair < long double, int > >, greater < pair < long double, int > > > q;
  q.push ({0, 1});
  while (!q.empty()) {
    int u = q.top().second;
    long double d_u = q.top().first;
    q.pop();
    if (d_u != d[u]) continue;

    for (auto edge : adj[u]) {
      int to = edge.first;
      long double len = edge.second;
      if (d[to] > d[u] + len) {
        d[to] = d[u] + len;
        q.push ({d[to], to});
      }
    }
  }

  cout << d[n] << '\n';
}
