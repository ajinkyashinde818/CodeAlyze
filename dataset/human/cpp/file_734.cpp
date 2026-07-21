#include <bits/stdc++.h>
using namespace std;
//#define int long long

int main() {
  int r, g, b, n;
  cin >> r >> g >> b >> n;
  int ans = 0;
  for (int i = 0; r * i <= n; i++) {
    for (int j = 0; r * i + j * b <= n; j++) {
      int x = n - r * i - b * j;
      if (x >= 0 && (x % g) == 0) ans++;
    }
  }
  cout << ans << endl;
}
