#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int r, g, b, n;
  while (cin >> r >> g >> b >> n) {
    int cnt = 0;
    for (int i = 0; i <= n / r; i++) {
      for (int j = 0; j <= (n - i*r) / g; j++) {
        if ((n - i*r - j*g) % b == 0) {
          cnt++;
        }
      }
    }
    cout << cnt << '\n';
  }
}
