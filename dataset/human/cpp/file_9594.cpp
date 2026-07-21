#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n), b(m);
  for (auto &&w : a) {
    cin >> w;
  }
  for (auto &&w : b) {
    cin >> w;
  }
  for (int i = 0; i <= n - m; i++) {
    for (int j = 0; j <= n - m; j++) {
      bool same = true;
      for (int k = 0; k < m; k++) {
        for (size_t l = 0; l < m; l++) {
          if (a[k + i][l + j] != b[k][l]) same = false;
        }
      }
      if (same) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
