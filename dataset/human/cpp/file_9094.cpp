#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  char a[n][n], b[m][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      cin >> b[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i + m - 1 >= n || j + m - 1 >= n) {
        continue;
      }
      bool f = true;
      for (int s = 0; s < m; s++) {
        for (int t = 0; t < m; t++) {
          if (a[i + s][j + t] != b[s][t]) {
            f = false;
          }
        }
      }
      if (f) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
