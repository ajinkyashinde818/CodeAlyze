#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Dijkstra {
  struct Edge {
    int to;
    T cost;
  };
  vector<int> prev;
  vector<vector<Edge>> g;
  Dijkstra(int n) : prev(n, -1), g(n) {}

  void addEdge(int u, int v, T w) {
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  vector<T> build(int s) {
    vector<T> dist(g.size(), -1);
    using Node = pair<T, int>;
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({dist[s] = 0, s});

    while (!pq.empty()) {
      auto d = pq.top().first;
      auto u = pq.top().second;
      pq.pop();
      if (dist[u] < d) continue;
      for (auto&& v : g[u]) {
        if (dist[v.to] < 0 || dist[v.to] > dist[u] + v.cost) {
          dist[v.to] = dist[u] + v.cost;
          prev[v.to] = u;
          pq.push({dist[v.to], v.to});
        }
      }
    }
    return dist;
  }
  vector<int> getPath(int t) {
    vector<int> path;
    for (; t != -1; t = prev[t]) path.push_back(t);
    reverse(begin(path), end(path));
    return path;
  }
};

int main() {
  int xs, ys, xt, yt;
  cin >> xs >> ys >> xt >> yt;
  int n;
  cin >> n;
  vector<int> x(n + 2), y(n + 2), r(n + 2);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> r[i];
  }
  int s = n;
  x[s] = xs;
  y[s] = ys;
  r[s] = 0;
  int t = n + 1;
  x[t] = xt;
  y[t] = yt;
  r[t] = 0;
  Dijkstra<double> g(n + 2);
  for (int i = 0; i < n + 2; i++) {
    for (int j = i + 1; j < n + 2; j++) {
      double d = hypot(abs(x[i] - x[j]), abs(y[i] - y[j])) - (r[i] + r[j]);
      if (d < 0) d = 0;
      g.addEdge(i, j, d);
    }
  }
  auto ans = g.build(s);
  cout << setprecision(10) << fixed;
  cout << ans[t] << endl;
}
