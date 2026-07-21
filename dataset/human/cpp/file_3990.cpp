#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <stack>
#include <queue>
#include <cstring>
#include <iterator>

#define FOR(n) for(int cnt=0;cnt<(n);++cnt)
#define FOR_R(it,cont) for(auto it=rbegin(cont);it!=rend(cont);++it)
#define FOR_F(it,cont) for(auto it=begin(cont);it!=end(cont);++it)
#define ALL(cont) begin(cont), end(cont)
#define LB(b,e,v) lower_bound(b,e,v)
#define UB(b,e,v) upper_bound(b,e,v)

using namespace std;
typedef pair<int,int> P;
struct Circle {
  int x,y,r;
};
P s,t;
int N;
Circle circles[1010];

struct Dijkstra {
  typedef double COST;
  static const int MAX_V = 1010;
  const COST INF = 1e15;
  struct Edge{int to;COST cost;};
  vector<Edge> edges[MAX_V];
  COST dist[MAX_V];
  void addEdge(int from, int to, COST cost) {
    edges[from].push_back({to,cost});
  }
  void solve(int start) {
    for(int i=0;i<MAX_V;++i) {
      dist[i] = INF;
    }
    dist[start] = 0;
    typedef pair<COST, int> QP;
    priority_queue<QP, vector<QP>, greater<QP> > Q;
    Q.push(QP(0,start));
    while(!Q.empty()) {
      QP cur = Q.top();Q.pop();
      if (cur.first > dist[cur.second]) continue;
      for(int i=0;i<edges[cur.second].size();++i) {
        Edge e = edges[cur.second][i];
        COST tcost = dist[cur.second] + e.cost;
        if (tcost < dist[e.to]) {
          dist[e.to] = tcost;
          Q.push(QP(tcost, e.to));
        }
      }
    }
  }
};

double distDouble(double x1, double y1, double x2, double y2) {
  double dx = x2-x1,dy = y2-y1;
  return sqrt(dx*dx+dy*dy);
}

Dijkstra dijkstra;

int main() {
  scanf("%d%d%d%d", &s.first, &s.second, &t.first, &t.second);
  scanf("%d", &N);
  FOR(N) {
    int x,y,r;
    scanf("%d%d%d", &x, &y, &r);
    circles[cnt].x=x;circles[cnt].y=y;circles[cnt].r=r;
  }
  circles[N] = {s.first,s.second,0};
  circles[N+1] = {t.first,t.second,0};
  N=N+2;
  for(int i=0;i<N;++i) {
    for(int j=i+1;j<N;++j) {
      Circle c1 = circles[i],c2 = circles[j];
      double dist = distDouble(c1.x,c1.y,c2.x,c2.y);
      dist -= (1.0*c1.r + 1.0*c2. r);
      if (dist <= 0) dist = 0;
      dijkstra.addEdge(i,j,dist);
      dijkstra.addEdge(j,i,dist);
    }
  }
  dijkstra.solve(N-2);
  printf("%.15f\n", dijkstra.dist[N-1]);
  return 0;
}
