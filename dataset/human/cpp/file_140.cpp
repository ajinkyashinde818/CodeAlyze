#include <iostream>
using namespace std;

int main() {
  int r, g, b, n, triplets = 0;
  cin >> r >> g >> b >>n;
  for (int i = 0; i <= n / r; ++i) {
    for (int j = 0; j <= n / g; ++j) {
      int t = n - i * r - j * g;
      if (t < 0) break;
      if (t % b == 0) ++triplets;
    }
  }
  cout << triplets << '\n';
  return 0;
}
