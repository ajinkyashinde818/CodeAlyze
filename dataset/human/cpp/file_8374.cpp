#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  string a[n], b[m];
  bool flag = false;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[j][i] == b[0][0]) {
        flag = true;
        for (int x = 0; x < m; x++) {
          for (int y = 0; y < m; y++) {
            if (a[j + y][i + x] != b[y][x]) {
              flag = false;
              break;
            }
          }
          if (!flag) break;
        }
        if (flag == true) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
