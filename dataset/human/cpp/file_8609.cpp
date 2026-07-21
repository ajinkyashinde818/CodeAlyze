#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  char a[n][n], b[m][m];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      cin >> a[i][j];
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j)
      cin >> b[i][j];
  }
  for (int i = 0; i + m <= n; ++i) {
    for (int j = 0; j + m <= n; ++j) {
      bool ok = 1;
      if (a[i][j] != b[0][0] || a[i + m - 1][j + m - 1] != b[m - 1][m - 1])
        ok = 0;
      for (int x = 0; x < m; ++x) {
        for (int y = 0; y < m; ++y) {
          if (a[i + x][j + y] != b[x][y])
            ok = 0;
          if (!ok)
            break;
        }
        if (!ok)
          break;
      }
      if (ok) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";
}
