#include <iostream>
using namespace std;

int main() {
  int r, g, b, n;
  cin >> r >> g >> b >> n;

  int ret = 0;
  for (int nr = 0; nr <= n / r; ++nr) {
    int m = n - nr * r;
    for (int ng = 0; ng <= m / g; ++ng) {
      int rem = m - ng * g;
      if (rem % b)
        continue;
      ++ret;
    }
  }
  cout << ret << "\n";

  return 0;
}
