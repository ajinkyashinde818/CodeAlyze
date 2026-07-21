#include <cstdio>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
#include <queue>

struct vertex
{
  long long x;
  long long y;
  long long r;
};

int main()
{
  long long sx, sy, tx, ty;
  int n;
  scanf("%lld%lld%lld%lld%d", &sx, &sy, &tx, &ty, &n);
  vertex vs[1002];
  for (int i = 0; i < n; ++i)
  {
    scanf("%lld%lld%lld", &vs[i].x, &vs[i].y, &vs[i].r);
  }
  vs[n] = vertex{sx, sy, 0};
  vs[n + 1] = vertex{tx, ty, 0};

  double edges[1002][1002];
  edges[n + 1][n + 1] = 0;
  for (int i = 0; i < n + 1; ++i)
  {
    edges[i][i] = 0;
    for (int j = i + 1; j < n + 2; ++j)
    {
      double dist = std::max(0., std::sqrt((vs[i].x - vs[j].x) * (vs[i].x - vs[j].x) + (vs[i].y - vs[j].y) * (vs[i].y - vs[j].y)) - (vs[i].r + vs[j].r));
      edges[i][j] = dist;
      edges[j][i] = dist;
    }
  }
  using pair = std::pair<double, int>;
  std::priority_queue<pair, std::vector<pair>, std::greater<pair>> q;
  double dist[1002];
  std::fill(dist, dist + n + 2, 1e18);
  q.emplace(0, n);
  while (q.size() > 0)
  {
    pair p = q.top(); q.pop();
    if (dist[p.second] < p.first) continue;
    for (int i = 0; i < n + 2; ++i)
    {
      if (p.first + edges[p.second][i] < dist[i])
      {
        dist[i] = p.first + edges[p.second][i];
        q.emplace(p.first + edges[p.second][i], i);
      }
    }
  }
  printf("%.12f\n", dist[n + 1]);
}
