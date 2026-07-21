#include <iostream>
#include <vector>

namespace {
void solve() {
  int32_t n;
  std::cin >> n;

  std::vector<int64_t> v(n, 0);

  int64_t s = 0, m = 1e9 + 1;
  int32_t c = 0;
  for (int32_t i = 0; i < n; i++) {
    std::cin >> v[i];
    if (v[i] < 0) {
      c++;
      s -= v[i];
      m = std::min(m, -v[i]);
    } else {
      s += v[i];
      m = std::min(m, v[i]);
    }
  }

  std::cout << (c & 1 ? s - m - m : s) << std::endl;
}
} // namespace

int32_t main(void) { solve(); }
