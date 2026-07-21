#include <stdio.h>
#include <math.h>
#include <set>
#include <utility>
using namespace std;

double max(double a, double b) {
  return a > b ? a : b;
}

int main(void) {
  int i, j, k, xs, ys, xt, yt, n;
  scanf("%d%d%d%d", &xs, &ys, &xt, &yt);
  scanf("%d", &n);
  double cost[n + 2][n + 2], dis[n + 2];
  int x[n], y[n], r[n];
  for(i = 0; i < n; ++i) scanf("%d%d%d", &x[i], &y[i], &r[i]);
  for(i = 0; i < n + 2; ++i) dis[i] = (double)1e10;
  dis[n] = 0.0;
  for(i = 0; i < n; ++i) {
    cost[i][n] = cost[n][i] = max(sqrt((double)(x[i] - xs) * (double)(x[i] - xs) + (double)(y[i] - ys) * (double)(y[i] - ys)) - (double)r[i], 0.0);
    cost[i][n + 1] = cost[n + 1][i] = max(sqrt((double)(x[i] - xt) * (double)(x[i] - xt) + (double)(y[i] - yt) * (double)(y[i] - yt)) - (double)r[i], 0.0);
  }
  i = 0;
  cost[n][n] = cost[n + 1][n + 1] = 0.0;
  cost[n][n + 1] = cost[n + 1][n] = sqrt((double)(xs - xt) * (double)(xs - xt) + (double)(ys - yt) * (double)(ys - yt));
  for(i = 0; i < n; ++i) for(j = 0; j < n; ++j) {
    if(i == j) cost[i][j] = 0.0;
    else cost[i][j] = max(sqrt((double)(x[i] - x[j]) * (double)(x[i] - x[j]) + (double)(y[i] - y[j]) * (double)(y[i] - y[j])) - (double)r[i] - (double)r[j], 0.0);
  }
  set< pair<double, int> > s;
  int now = n;
  for(i = 0; i < n; ++i) s.insert({dis[i], i});
  s.insert({dis[n + 1], n + 1});
  while(s.size()) {
    for(i = 0; i < n + 2; ++i) if(dis[now] + cost[now][i] < dis[i]) {
      s.erase(s.find({dis[i], i}));
      dis[i] = dis[now] + cost[now][i];
      s.insert({dis[i], i});
    }
    now = (*s.begin()).second;
    s.erase(s.begin());
  }
  printf("%.12f", dis[n + 1]);
  return 0;
}
