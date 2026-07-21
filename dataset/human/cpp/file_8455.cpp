#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, m;
  cin >> n >> m;
  char a[n][n], b[m][m];
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < m; j++) {
      cin >> b[i][j];
    }
  }
  bool tf = false;

  if (n==m) {
    bool match = true;
    for (size_t i = 0; i < m and match; i++) {
      for (size_t j = 0; j < m and match; j++) {
        if (b[i][j]!=a[i][j]) match=false;
      }
    }
    if (match) tf = true;
  }
  else {
    for (size_t i = 0; i < n-m and tf == false; i++) {
      for (size_t j = 0; j < n-m and tf == false; j++) {
        bool match = true;
        for (size_t k = 0; k < m; k++) {
          for (size_t l = 0; l < m; l++) {
            if (b[k][l]!=a[i+k][j+l]) {
              match = false;
              break;
            }
          }
        }
        if (match) tf = true;
      }
    }
  }
  if (tf) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
