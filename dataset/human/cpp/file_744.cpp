#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(false);

  int r, g, b, n;
  cin >> r >> g >> b >> n;

  vector<int> dp(n + 1);
  for (int i = 0; i < n + 1; ++i)
    for (int j = 0; j < n + 1; ++j)
      if (i * r + j * g < n + 1)
        ++dp[i * r + j * g];

  int64_t ans = 0;
  for (int i = 0; i < n + 1; ++i) {
    int x = n - i * b;
    if (x < 0) continue;
    ans += dp[x];
  }

  cout << ans << endl;

  return 0;
}
