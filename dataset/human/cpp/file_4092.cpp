#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>

struct Barrier {
  double x;
  double y;
  double r;

  Barrier() : x(0), y(0), r(-1) {
  }

  Barrier(double x_, double y_, double r_) : x(x_), y(y_), r(r_) {
  }
};

Barrier barriers[1002];
double costs[1002][1002];
double costFromStart[1002];
const int start = 0;
const int goal = 1001;
const double inf = HUGE_VAL;

void prepare() {
  for (int i = 0; i < 1002; i++) {
    for (int j = 0; j < 1002; j++) {
      auto from = barriers[i];
      auto to = barriers[j];

      if (from.r < 0 || to.r < 0) {
        costs[i][j] = inf;
      }

      auto dx = from.x - to.x;
      auto dy = from.y - to.y;

      auto distance = std::sqrt(dx * dx + dy * dy);
      auto cost = std::max(0.0, distance - from.r - to.r);

      costs[i][j] = cost;
    }
  }
}

void solve() {
  // (cost, barrier_index)
  std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int> >, std::greater<std::pair<double, int> > > q;

  costFromStart[start] = 0;
  for (int i = 1; i < 1002; i++) {
    costFromStart[i] = inf;
  }

  q.push(std::make_pair(0.0, 0));
  while (!q.empty()) {
    double costFrom = q.top().first;
    int from = q.top().second;
    q.pop();

    for (int to = 0; to < 1002; to++) {
      double edgeCost = costs[from][to];
      if (edgeCost >= inf) {
        break;
      }

      double costTo = costFrom + edgeCost;
      if (costTo < costFromStart[to]) {
        costFromStart[to] = costTo;
        q.push(std::make_pair(costTo, to));
      }
    }
  }
}

int main() {
  int xs, ys, xt, yt;
  int N;
  scanf("%d%d%d%d", &xs, &ys, &xt, &yt);
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    int x, y, r;
    scanf("%d%d%d", &x, &y, &r);
    barriers[i] = Barrier(x, y, r);
  }
  barriers[start] = Barrier(xs, ys, 0);
  barriers[goal] = Barrier(xt, yt, 0);

  prepare();
  solve();

  printf("%.10f\n", costFromStart[goal]);

  return 0;
}
