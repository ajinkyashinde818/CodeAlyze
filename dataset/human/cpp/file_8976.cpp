#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;

  cin >> n >> m;

  vector<string> a(n), b(m);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  for (int i = 0; i <= n - m; i++) {
    for (int l = 0; l <= n - m; l++) {
      int flag = 1;
      for (int j = 0; j < m && flag; j++) {
        for (int k = 0; k < m && flag; k++) {
          if (a[j + i][k + l] != b[j][k]) {
            flag = 0;
            break;
          } else if (j == m - 1 && k == m - 1) {
            cout << "Yes";
            return 0;
          }
        }
      }
    }
  }

  cout << "No";

  return 0;
}
