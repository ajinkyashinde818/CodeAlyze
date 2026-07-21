#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
  int m, n;
  cin >> n >> m;

  vector<string> a(n);
  for (auto &row : a)
    cin >> row;
  vector<string> b(m);
  for (auto &row : b)
    cin >> row;

  for (int i = 0; i + m - 1 < n; i++) {
    for (int j = 0; j + m - 1 < n; j++) {
      bool ok = true;
      for (int k = 0; k < m; k++) {
        for (int l = 0; l < m; l++) {
          if (a[i + k][j + l] != b[k][l]) {
            ok = false;
            goto _next;
          }
        }
      }
    _next:;

      if (ok) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;

  return 0;
}
