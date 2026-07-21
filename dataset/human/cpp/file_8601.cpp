#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, i, j, s, t, cnt = 0, ans = 0;
  cin >> n >> m;
  vector<string> a(n), b(m);
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < m; i++) {
    cin >> b[i];
  }
  if (n - m != 0) {
    for (s = 0; s < n - m; ++s) {
      for (t = 0; t < n - m; ++t) {
        cnt = 0;
        for (i = 0; i < m; ++i) {
          for (j = 0; j < m; ++j) {
            if (a[s + i][t + j] == b[i][j]) {
              ++cnt;
            }
          }
        }
        if (cnt == m * m) {
          ans = 1;
        }
      }
    }
  } else {
    cnt = 0;
    for (i = 0; i < m; i++) {
      for (j = 0; j < m; j++) {
        if (a[i][j] == b[i][j]) {
          ++cnt;
        }
      }
    }
    if (cnt == m * m) {
      ans = 1;
    }
  }
  if (ans) {
    cout << "Yes"
         << "\n";
  } else {
    cout << "No"
         << "\n";
  }
  return 0;
}
