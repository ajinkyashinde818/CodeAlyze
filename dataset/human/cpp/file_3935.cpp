#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
typedef pair<ld, int> P;
ld INF = 100000000000.0;

int N;
ld Graph[1100][1100];

ld dijkstra() {
  ld res[1100];
  for (int i = 0; i < 1100; i++) {
    res[i] = INF;
  }
  priority_queue<P,vector<P>,greater<P>> Q;
  Q.push(make_pair((ld)0,0));
  while (!Q.empty()) {
    P p = Q.top();
    Q.pop();
    if (res[p.second] <= p.first) {
      continue;
    }
    res[p.second] = p.first;
    for (int i = 0; i < N+2; i++) {
      if (p.first + Graph[p.second][i] < res[i]) {
        
        Q.push(make_pair(p.first + Graph[p.second][i],i));
      }
    }
  }
  return res[N+1];
}

int main() {
  ld sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;
  for (int i = 0; i < 1100; i++) {
    for (int j = 0; j < 1100; j++) {
      Graph[i][j] = INF;
    }
  }
  cin >> N;
  vector<ld> x;
  vector<ld> y;
  vector<ld> r;
  x.push_back(sx);
  y.push_back(sy);
  r.push_back((ld)0);
  for (int i = 0; i < N; i++) {
    ld xx,yy,rr;
    cin >> xx >> yy >> rr;
    x.push_back(xx);
    y.push_back(yy);
    r.push_back(rr);
  }
  x.push_back(tx);
  y.push_back(ty);
  r.push_back((ld)0);
  for (int i = 0; i < N+2; i++) {
    for (int j = 0; j < N+2; j++) {
      if (i == j) {
        continue;
      }
      ld dis = sqrt( ((x[i] - x[j]) * (x[i] - x[j])) + ((y[i] - y[j]) * (y[i] - y[j])) );
      if (dis - r[i] - r[j] <= (ld)0) {
        Graph[i][j] = 0;
      } else {
        Graph[i][j] = dis - r[i] - r[j];
      }
    }
  }
  ld ans = dijkstra();
  cout << setprecision(120) << ans << endl;
  return 0;
}
