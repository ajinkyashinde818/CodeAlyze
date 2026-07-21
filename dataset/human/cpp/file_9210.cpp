#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, m;
  cin >> n >> m;
  char a[n + 1][n + 1], b[m * 1][m + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> b[i][j];
    }
  }

  bool exist = false;
  for (int i = 0; i <= n - m; i++) {
    for (int j = 0; j <= n - m; j++) {
      bool match = true;
      for (int k = 1; k <= m; k++) {
        for (int l = 1; l <= m; l++) {
          if (a[k + i][l + j] != b[k][l]) {
            match = false;
          }
        }
      }
      if (match) {
        exist = true;
      }
    }
  }
  if (exist) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
