#include<bits/stdc++.h>
using namespace std;

using D = double;
struct Point {D x, y;};
struct Circle {D x, y, r;};
struct Edge {int from, to; D weight;};
using Graph = vector<vector<Edge>>;

using Node = pair<D, int>;
const D INF = 1e10;

D distance(auto c1, auto c2) {
  auto d = hypot(c1.x-c2.x, c1.y-c2.y);
  auto r = c1.r + c2.r;
  return max(0.0, d - r);
}

int main() {
  Point S, T;
  cin >> S.x >> S.y >> T.x >> T.y;
  int N;
  cin >> N;
  vector<Circle> C(N);
  for(auto& c: C) cin >> c.x >> c.y >> c.r;

  Graph G(N+2);
  const auto B = N;
  const auto E = N+1;
  for(auto i=0; i<N; ++i) for(auto j=0; j<N; ++j) if(i != j) G[i].push_back({i, j, distance(C[i], C[j])});
  for(auto i=0; i<N; ++i) G[B].push_back({B, i, distance(Circle{S.x, S.y, 0.0}, C[i])});
  for(auto i=0; i<N; ++i) G[i].push_back({i, E, distance(C[i], Circle{T.x, T.y, 0.0})});
  G[B].push_back({B, E, distance(Circle{S.x, S.y, 0.0}, Circle{T.x, T.y, 0.0})});

  vector<D> d(N+2, INF);
  priority_queue<Node, vector<Node>, greater<Node>> q;
  q.emplace(0, B);
  while(!q.empty()) {
    auto w = q.top().first;
    auto v = q.top().second;
    q.pop();
    if(d[v] != INF) continue;
    d[v] = w;
    for(auto e: G[v]) if(w + e.weight < d[e.to]) q.emplace(w + e.weight, e.to);
  }
  cout << setprecision(8) << fixed << d[E] << endl;
}
