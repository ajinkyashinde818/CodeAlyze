#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, n;
  cin >> a >> b >> c >> n;
  int ret = 0;
  for (int i = 0; i * a <= n; i++) {
    for (int j = 0; i * a + j * b <= n; j++) {
      if ((n - (i * a + j * b)) % c) continue;
      ret++;
    }
  }
  cout << ret << endl;
  return 0;
}
