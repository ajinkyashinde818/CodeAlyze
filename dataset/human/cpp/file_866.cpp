#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int r, g, b, n;
  cin >> r >> g >> b >> n;

  int ans = 0;

  for (int i = 0; i <= 3000; i++) {
    for (int j = 0; j <= 3000; j++) {
      // for (int k = 1; k < 3000; k++) {
      int m = n - (r * i + g * j);
      if (m >= 0 && m % b == 0) ans++;
      // }
    }
  }

  cout << ans << endl;
}
