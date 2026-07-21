#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<string> A(n);
  for (auto &a : A) cin >> a;
  vector<string> B(m);
  for (auto &b : B) cin >> b;
  bool ok = true;
  for (int i = 0; i+m < n; ++i) {
    for (int j = 0; j+m < n; ++j) {
      ok = true;
      for (int k = 0; k < m; ++k) {
        for (int l = 0; l < m; ++l) {
          if (A[i+k][j+l] != B[k][l]) {
            ok = false;
            break;
          }
        }
        if (!ok) break;
      }
      if (ok) break; 
    }
    if (ok) break;
  }
  cout << (ok ? "Yes" : "No") << endl;

  return 0;
}
