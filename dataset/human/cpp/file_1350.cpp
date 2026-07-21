#include "bits/stdc++.h"

using namespace std;

int main(void) {
  int r, g, b, n; cin >> r >> g >> b >> n;
  int sum = 0;
  for (int i = 0; i <= n / r; i++) {
    for (int j = 0; j <= n / g; j++) {
      int left = n - (r * i + g * j);
      if (left % b == 0 && 0 <= left) {
        sum++;
      }
    }
  }
  cout << sum << endl;
  return 0;
}
