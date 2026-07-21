#include <bits/stdc++.h>

using namespace std;

double x[1010], y[1010], r[1010];
int N;

typedef pair<double, int> P;

double INF = 1e15;
double EPS = 1e-9;

double dijkstra()
{
  priority_queue<P, vector<P>, greater<P> > que;
  vector<double> mincost(N, INF);
  que.push(P(0.0, 0));
  mincost[0] = 0.0;
  while(!que.empty()) {
    P p = que.top(); que.pop();
    double dist = p.first; int cur = p.second;
    if(cur == 1) return dist;
    if(dist > mincost[cur] + EPS) continue;
    for(int i = 0; i < N; i++) {
      if(i == cur) continue;
      double hoge = (x[i]-x[cur])*(x[i]-x[cur])+(y[i]-y[cur])*(y[i]-y[cur]);
      double norm = sqrt(hoge), bari = r[i]+r[cur];
      double cost = 0.0;
      if(hoge > bari*bari) cost = norm - bari;
      if(mincost[i] > dist + cost + EPS) {
	que.push(P(cost + dist, i));
	mincost[i] = cost + dist;
      }
    }
  }
  return -1.0;
}

int main()
{
  cin >> x[0] >> y[0] >> x[1] >> y[1]; r[0] = r[1] = 0.0;
  cin >> N; N += 2;
  for(int i = 2; i < N; i++) cin >> x[i] >> y[i] >> r[i];
  printf("%.10f\n", dijkstra());
  return 0;
}
