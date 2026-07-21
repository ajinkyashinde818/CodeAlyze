#include <bits/stdc++.h>

int main() {
  int64_t n;
  std::cin >> n;
  std::vector<int64_t> a(n);

  int64_t m = 0;
  bool zero = false;

  for (auto &i : a) {
    std::cin >> i;
    if (i < 0) {
      m++;
      i = -i;
    } else if (i == 0) {
      zero = true;
    }
  }

  const auto sum = std::accumulate(a.cbegin(), a.cend(), 0ll);
  if (m % 2 == 0 || zero) {
    std::cout << sum << std::endl;
  } else {
    const auto min = *std::min_element(a.cbegin(), a.cend());
    std::cout << sum - 2 * min << std::endl;
  }
  return 0;
}
