#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int64_t> as;
  int64_t sum = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    sum += a;
    as.push_back(sum);
  }
  if (as.size() == 2) {
    std::cout << std::abs(sum - 2 * as[0]) << std::endl;
    return 0;
  }
  std::vector<int64_t> diff;
  for (int i = 1; i < n - 1; ++i) {
    diff.push_back(std::abs(sum - 2 * as[i]));
  }
  std::sort(diff.begin(), diff.end());
  std::cout << diff[0] << std::endl;
  return 0;
}
