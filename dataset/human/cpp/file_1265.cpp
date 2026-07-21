#include <bits/stdc++.h>

using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int ans = 0;
  for (int i = 0; i * a <= d; i++) {
    for (int j = 0; i * a + j * b <= d; j++) {
      if ((d - i * a - j * b) % c == 0) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
