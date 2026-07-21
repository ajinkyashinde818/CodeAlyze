#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int MAX32 = 2147483647;
const double PI = 3.14159265358979323846;

int main() {
  int r, g, b, n, cnt = 0;
  cin >> r >> g >> b >> n;
  for (int i = 0; i * r <= n; i++) {
    for (int j = 0; i * r + j * g <= n; j++) {
      if ((n - i * r - j * g) % b == 0) {
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}
