#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  string sn[n], sm[m];
  for (int i = 0; i < n; i++) {
    cin >> sn[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> sm[i];
  }

  bool a = false;
  for (int i = 0; i + m <= n; i++) {
    for (int j = 0; j + m <= n; j++) {
      bool b = true;
      for (int k = 0; k < m; k++) {
        for (int l = 0; l < m; l++) {
          if (sn[i + k][j + l] != sm[k][l]) b = false;
        }
      }
      if (b) a = true;
    }
  }
  puts(a ? "Yes\n" : "No\n");
  return 0;
}
