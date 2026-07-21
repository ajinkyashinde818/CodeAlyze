#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

class vertex {
 public:
  double x;
  double y;
  double r;
};

int main() {
  unsigned N;
  double x0, y0, x1, y1;
  std::cin >> x0 >> y0 >> x1 >> y1;
  std::cin >> N;
  std::vector<vertex> v(N + 2);
  v[0].x = x0;
  v[0].y = y0;
  v[0].r = 0.0;
  v[1].x = x1;
  v[1].y = y1;
  v[1].r = 0.0;
  for (unsigned i = 2; i < N + 2; ++i) {
    std::cin >> v[i].x >> v[i].y >> v[i].r;
  }
  std::vector<std::vector<double>> cost(N + 2, std::vector<double>(N + 2));
  for (unsigned i = 0; i < N + 2; ++i) {
    cost[i][i] = 0.0;
  }
  for (unsigned i = 0; i < N + 2; ++i) {
    for (unsigned j = 0; j < i; ++j) {
      double tmp = std::max(0.0, std::sqrt(std::pow(v[i].x - v[j].x, 2) + std::pow(v[i].y - v[j].y, 2)) - (v[i].r + v[j].r));
      cost[i][j] = tmp;
      cost[j][i] = tmp;
    }
  }
  for (unsigned k = 0; k < N + 2; ++k) {
    for (unsigned i = 0; i < N + 2; ++i) {
      for (unsigned j = 0; j < N + 2; ++j) {
        cost[i][j] = std::min(cost[i][j], cost[i][k] + cost[k][j]);
      }
    }
  }
  std::cout << std::setprecision(16) << cost[0][1];
  return 0;
}
