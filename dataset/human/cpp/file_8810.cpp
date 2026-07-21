#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<string> a(n), b(m);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  int succ = true;
  for (int i = 0; i < n - m; ++i) {
    for (int j = 0; j < n - m; ++j) {
      succ = true;
      for (int k = 0; k < m; ++k) {
        for (int l = 0; l < m; ++l) {
          if (b[k][l] != a[i + k][j + l]) {
            succ = false;
            break;
          }
        }
        if (!succ) break;
      }
      if (succ) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  if (succ) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
