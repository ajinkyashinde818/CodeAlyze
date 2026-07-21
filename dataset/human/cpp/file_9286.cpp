#include <bits/stdc++.h>
using namespace std;

int main () {
  int n, m; cin >> n >> m;
  string base[n], in[m];
  for (int i = 0 ; i < n; i++) cin >> base[i];
  for (int i = 0; i < m; i++) cin >> in[i];
  int nl = base[0].size();
  int ml = in[0].size();
  if (ml > nl || m > n) {
    cout << "No" << endl;
  } else {
    bool ok = false;
    for (int i = 0; i < n-m+1; i++) {
      for (int j = 0; j < nl-ml+1; j++) {
        bool oks = true;
        for (int ii = 0; ii < m; ii++) {
          for (int jj = 0; jj < ml; jj++) {
            if (base[i+ii][j+jj] != in[ii][jj]) oks = false;
          }
        }
        ok |= oks;
      }
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}
