#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0); ios::sync_with_stdio(false);
  double xs, ys, xt, yt; cin >> xs >> ys >> xt >> yt;
  int n; cin >> n;
  vector<double> x(n + 2), y(n + 2), r(n + 2); for (int i = 1; i <= n; i++) cin >> x[i] >> y[i] >> r[i];
  x[0] = xs; y[0] = ys; r[0] = 0.0;
  x[n + 1] = xt; y[n + 1] = yt; r[n + 1] = 0.0;
  struct adj { int to; double cost; };
  vector<vector<adj>> G(n + 2);
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= n + 1; j++) {
      if (j == i) continue;
      G[i].push_back(adj{j, max(0.0, hypot(x[j] - x[i], y[j] - y[i]) - r[i] - r[j])});
    }
  }
  vector<double> d(n + 2, 1e12);
  d[0] = 0.0;
  typedef pair<double, int> P;
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push(P(0.0, 0));
  while (not pq.empty()) {
    P p = pq.top(); pq.pop();
    int v = p.second;
    if (d[v] < p.first) continue;
    for (auto i : G[v]) {
      if (d[i.to] > d[v] + i.cost) {
        d[i.to] = d[v] + i.cost;
        pq.push(P(d[i.to], i.to));
      }
    }
  }
  cout << setprecision(12) << d[n + 1] << '\n';
  return 0;
}
