#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
using ll = long long;
const double INF = 1ll << 62;

int main() {
  ll xs, ys, xt, yt;
  cin >> xs >> ys >> xt >> yt;
  int N;
  cin >> N;
  N += 2;
  vector<ll> x(N), y(N), r(N);
  x[0] = xs; y[0] = ys; r[0] = 0;
  x[1] = xt; y[1] = yt; r[1] = 0;
  for (int i = 2; i < N; i++) {
    cin >> x[i] >> y[i] >> r[i];
  }
  vector<vector<pair<int, double>>> G(N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      double dx = x[i] - x[j];
      double dy = y[i] - y[j];
      double d = max(0.0, sqrt(dx * dx + dy * dy) - r[i] - r[j]);
      G[i].emplace_back(j, d);
    }
  }
  vector<double> dist(N, INF);
  priority_queue<pair<double, int>> q;
  q.emplace(0, 0);
  dist[0] = 0;
  while (!q.empty()) {
    auto p = q.top(); q.pop();
    int v = p.second;
    for (auto e: G[v]) {
      int u = e.first;
      double c = e.second;
      if (dist[v] + c < dist[u]) {
        dist[u] = dist[v] + c;
        q.emplace(-dist[u], u);
      }
    }
  }
  printf("%.10f\n", dist[1]);
  return 0;
}
