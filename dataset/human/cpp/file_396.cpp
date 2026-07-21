#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int r, g, b, n;
  cin >> r >> g >> b >> n;
  ll ans = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (r * i + g * j > n) continue;
      if ((n - (r * i + g * j)) % b == 0) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
