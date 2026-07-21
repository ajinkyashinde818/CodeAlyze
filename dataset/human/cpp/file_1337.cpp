#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll r, g, b, n, ans = 0;
  cin >> r >> g >> b >> n;

  for (int i = 0; i * r <= n; i++) {
    for (int j = 0; i * r + j * g <= n; j++) {
      if ((n - i * r - j * g) % b == 0) ans++;
    }
  }
  cout << ans << endl;
}
