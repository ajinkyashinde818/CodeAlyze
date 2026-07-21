#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  std::cin >> n;
  static std::array<int, 200001> as;

  int64_t x;
  std::cin >> x;

  int64_t y = 0;
  int a;
  for (int i = 1; i < n - 1; i++) {
    std::cin >> a;
    y += a;
    as[i] = a;
  }
  std::cin >> a;
  y += a;

  int64_t ret = abs(x - y);
  for (int i = 1; i < n - 1; i++) {
    int const aa = as[i];
    x += aa;
    y -= aa;
    ret = std::min(abs(x - y), ret);
  }
  std::cout << ret << std::endl;
  return 0;
}
