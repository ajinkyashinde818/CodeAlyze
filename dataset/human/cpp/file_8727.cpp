#include <iostream>
#include <cstdint>
#include <vector>

int main() {
  std::int_fast64_t n, m;
  std::cin >> n >> m;
  std::vector<std::vector<char>> a(n, std::vector<char>(n)), b(m, std::vector<char>(m));
  for (std::vector<char>& a_i : a) {
    for (char& a_ij : a_i) {
      std::cin >> a_ij;
    }
    std::cin.get();
  }
  for (std::vector<char>& b_i : b) {
    for (char& b_ij : b_i) {
      std::cin >> b_ij;
    }
    std::cin.get();
  }

  for (std::int_fast64_t base_y = 0; base_y <= n - m; ++base_y) {
    for (std::int_fast64_t base_x = 0; base_x <= n - m; ++base_x) {
      for (std::int_fast64_t by = 0; by < m; ++by) {
        for (std::int_fast64_t bx = 0; bx < m; ++bx) {
          const std::int_fast64_t ay = base_y + by;
          const std::int_fast64_t ax = base_x + bx;
          if (a[ay][ax] != b[by][bx]) {
            goto NEXT_LOOP;
          }
        }
      }
      std::cout << "Yes" << std::endl;
      return 0;
    NEXT_LOOP:
      ;
    }
  }
  std::cout << "No" << std::endl;
  return 0;
}
