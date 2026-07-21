#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld INF = 1e18;
typedef pair< ld, int > P;

struct Graph {

  struct edge {
    int to; ld cost;
  };

  int V;
  vector< vector< edge > > Es;

  Graph(int v) {
    init(v);
  }

  void init(int v) {
      V = v;
      Es.resize(v);
  }

  void add(int from, int to, ld cost) {
    Es[from].push_back((edge){to, cost});
  }

  void show() {
    for (int v = 0; v < V; v++) {
      cout << "v = " << v << endl;
      for (auto e : Es[v]) {
        cout << e.to << " " << e.cost << endl;
      }
      cout << endl;
    }
  }

  vector< ld > dijkstra(int s) {
    vector< ld > dist(V, INF);
    dist[s] = 0.0;
    priority_queue< P, vector< P >, greater< P > > que;
    que.push(P(0.0, s));
    while (!que.empty()) {
      P p = que.top();
      que.pop();
      int v = p.second;
      if (dist[v] < p.first) continue;
      for (auto e : Es[v]) {
        ld d = dist[v] + e.cost;
        if (d < dist[e.to]) {
          dist[e.to] = d;
          que.push(P(d, e.to));
        }
      }
    }
    return dist;
  }

  vector< ld > bellmanford(int s) {
    vector< ld > dist(V, INF);
    dist[s] = 0.0;
    int loopCnt = 0;
    while (true) {
      bool update = false;
      for (int v = 0; v < V; v++) {
        if (dist[v] == INF) continue;
        for (auto e : Es[v]) {
          ld d = dist[v] + e.cost;
          if (d < dist[e.to]) {
            dist[e.to]= d;
            update = true;
          }
        }
      }
      if (!update) break;
      if (loopCnt == V+1) return vector< ld >(V, -INF);
      loopCnt += 1;
    }
    return dist;
  }

};

ld dist(ld x0, ld y0, ld x1, ld y1) {
  ld xd = x0-x1, yd = y0-y1;
  return sqrt(xd*xd+yd*yd);
}

int main() {
  ld xs, ys, xt, yt, N;
  cin >> xs >> ys >> xt >> yt >> N;
  vector< ld > x(N+2), y(N+2), r(N+2);
  x[0] = xs; y[0] = ys; r[0] = 0;
  x[N+1] = xt; y[N+1] = yt; r[N+1] = 0;
  for (int i = 1; i <= N; i++) cin >> x[i] >> y[i] >> r[i];
  Graph G(N+2);
  for (int i = 0; i < N+1; i++) {
    for (int j = i+1; j < N+2; j++) {
      ld d = max((ld)0.0, dist(x[i],y[i],x[j],y[j])-r[i]-r[j]);
      G.add(i, j, d);
      G.add(j, i, d);
    }
  }
  cout << fixed << setprecision(12) << G.bellmanford(0)[N+1] << endl;
}
