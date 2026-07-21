#include <iostream>
#include <climits>
#include <vector>
#include <numeric>
#include <cmath>

int main() {
  int n;
  std::cin >> n;
  std::vector<int64_t> a;
  for (int i = 0; i < n; i++) {
    int64_t v;
    std::cin >> v;
    a.push_back(v);
  }

  int64_t min = LONG_MAX;  
  int64_t total = 0;
  for (int v : a) {
    total += v;
  }
  int64_t x = 0;
  int64_t y = total;
  for (auto it = a.begin(); it < a.end() - 1; it++) {
    x += *it;
    y -= *it;
    int64_t diff = std::abs(x - y);
    if (diff < min)
      min = diff;
  }
  std::cout << min << std::endl;
  return 0;
}
