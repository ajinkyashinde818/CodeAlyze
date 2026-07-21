#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

struct WEdge {
  int from, to;
  double weight;
  WEdge(int from, int to, double weight) : from(from), to(to), weight(weight) {}
};

// Verified at AOJ-GRL1A.
tuple<vector<double>, vector<int>>
ShortestPath(vector<vector<WEdge>>& graph, int s) {
  int n = graph.size();
  vector<double> distances(n, DBL_MAX);
  vector<int> parents(n, -1);
  struct State {
    int v, parent;
    double weight;
  };
  auto compare_state = [](State s1, State s2) {
    return s1.weight > s2.weight;
  };
  priority_queue<State, vector<State>, decltype(compare_state)>
      pq(compare_state);

  pq.push(State({s, -1, 0}));
  vector<int> visited(n);
  while(!pq.empty()) {
    State s = pq.top();
    pq.pop();
    if (visited[s.v]) continue;
    visited[s.v] = true;
    distances[s.v] = s.weight;
    parents[s.v] = s.parent;
    for (const auto& e : graph[s.v]) {
      if (visited[e.to]) continue;
      State next = State({e.to, s.v, s.weight + e.weight});
      pq.push(next);
    }
  }
  return make_tuple(distances, parents);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cout << fixed << setprecision(10);

  vector<double> xs(2);
  vector<double> ys(2);
  vector<double> rs(2);
  cin >> xs[0] >> ys[0] >> xs[1] >> ys[1];
  int n;
  cin >> n;
  xs.resize(n + 2);
  ys.resize(n + 2);
  rs.resize(n + 2);
  for (int i = 0; i < n; i++) {
    cin >> xs[i + 2] >> ys[i + 2] >> rs[i + 2];
  }

  vector<vector<WEdge>> graph(n + 2);
  for (int i = 0; i < n + 2; i++) {
    for (int j = 0; j < n + 2; j++) {
      if (i == j) continue;
      double dx = xs[i] - xs[j];
      double dy = ys[i] - ys[j];
      double d2 = dx * dx + dy * dy;
      double r = rs[i] + rs[j];
      double r2 = r * r;
      double w = max(sqrt(d2) - sqrt(r2), 0.0);
      graph[i].push_back(WEdge(i, j, w));
    }
  }

  vector<double> dists;
  tie(dists, ignore) = ShortestPath(graph, 0);
  cout << dists[1] << endl;
}
