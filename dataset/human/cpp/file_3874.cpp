#include <bits/stdc++.h>
using namespace std;

struct p {
  long x, y;
};
struct circle {
  p c;
  long r;
};
int main() {
  p s, t;
  cin>>s.x>>s.y>>t.x>>t.y;
  int n;
  cin>>n;
  circle c[n+2];
  for (int i=1; i<=n; i++) cin>>c[i].c.x>>c[i].c.y>>c[i].r;
  c[0].c = s;
  c[0].r = 0;
  c[n+1].c = t;
  c[n+1].r = 0;

  vector<pair<double, int> > g[n+2];
  for (int i=0; i<n+2; i++) {
    for (int j=i+1; j<n+2; j++) {
      double d = sqrt(pow(c[i].c.x - c[j].c.x, 2) + pow(c[i].c.y - c[j].c.y, 2));
      double w = max(d - c[i].r - c[j].r, 0.0);
      g[i].emplace_back(w, j);
      g[j].emplace_back(w, i);
    }
  }
  priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int>>> pq;

  bool used[n+2];
  for (int i=0; i<n+2; i++) used[i] = false;
  double d[n+2];
  double inf = 2 * 1e12;
  for (int i=0; i<n+2; i++) d[i] = inf;
  pq.push(make_pair(0, 0));
  d[0] = 0.0;
  while (!pq.empty()) {
    auto top = pq.top();
    pq.pop();
    double d_cur = top.first;
    int cur = top.second;
    if (used[cur]) {
      continue;
    }
    used[cur] = true;
    for (auto e: g[cur]) {
      double w = e.first;
      int to = e.second;
      if (used[to]) {
        continue;
      }
      if (d[cur] + w < d[to]) {
        d[to] = d[cur] + w;
        pq.push(make_pair(d[to], to));
      }
    }
  }
  printf("%.9lf\n", d[n+1]);
}
