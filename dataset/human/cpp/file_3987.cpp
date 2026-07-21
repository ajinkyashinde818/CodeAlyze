#include <bits/stdc++.h>
using namespace std;
long long x[1005], y[1005], r[1005];
double dist[1005];
bool vis[1005];
double d(double dx, double dy, double sr) {
  return max(0.0, sqrt(dx * dx + dy * dy) - sr);
}
int main() {
  scanf("%lld %lld %lld %lld", &x[0], &y[0], &x[1], &y[1]);
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= n + 1; i++) {
    scanf("%lld %lld %lld", &x[i], &y[i], &r[i]);
  }
  priority_queue<pair<double, int> > pq;
  pq.push({0.0, 0});
  while (!pq.empty()) {
    auto p = pq.top();
    pq.pop();
    if (vis[p.second]) continue;
    vis[p.second] = true;
    dist[p.second] = -p.first;
    for (int i = 0; i <= n + 1; i++) {
      if (vis[i]) continue;
      pq.push({p.first - d(x[p.second] - x[i], y[p.second] - y[i], r[p.second] + r[i]), i});
    }
  }
  printf("%.9lf\n", max(0.0, dist[1]));
  return 0;
}
