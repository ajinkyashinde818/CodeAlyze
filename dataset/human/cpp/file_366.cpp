#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, g, b, n, cnt = 0;

  cin >> r >> g >> b >> n;

  for (int i = 0; i * r <= n; i++) {
    for (int j = 0; j * g + i * r <= n; j++) {
      if (i * r + j * g == n) {
        cnt++;
      } else if (i * r + j * g < n) {
        if ((n - (i * r + j * g)) % b == 0) {
          cnt++;
        }
      }
    }
  }

  cout << cnt;

  return 0;
}
