#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<string> b(m);
  for (int i = 0; i < m; i++)
    cin >> b[i];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == b[0][0]) {
        if (j <= n - m && i <= n - m) {
          int cnt = 0;
          for (int z = 0; z < m; z++) {
            if (a[i + z].substr(j, m) == b[z]) { cnt++; }
          }
          if (cnt == m) {
            cout << "Yes" << endl;
            return 0;
          }
        }
      }
    }
  }
  cout << "No" << endl;
}
