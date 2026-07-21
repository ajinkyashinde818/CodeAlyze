#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int r, g, b, n;
  cin >> r >> g >> b >> n;
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (i * r + j * g <= n && (n - i * r - j * g) % b == 0) {
        ans++;
      }
    }
  } 
  cout << ans << endl;
  return 0;
}
