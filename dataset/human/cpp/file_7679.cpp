#include <bits/stdc++.h>

int main() {
  int64_t n;
  std::cin >> n;
  std::vector<int64_t> a(n);
  for (auto &i : a) {
    std::cin >> i;
  }

  int64_t sum = std::accumulate(a.cbegin(), a.cend(), static_cast<int64_t>(0));

  int64_t ans = std::abs((sum - a[0]) - a[0]);

  int64_t tmp = 0;
  for (int64_t i = 0; i < n - 1; i++) {
    tmp += a[i];
    sum -= a[i];
    ans = std::min(ans, std::abs(tmp - sum));
  }

  std::cout << ans << std::endl;
  return 0;
}
