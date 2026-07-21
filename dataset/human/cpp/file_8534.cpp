#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<string> b(m);
  for (int i = 0; i < m; i++) cin >> b[i];
  
  bool ans;
  
  for (int r = 0; r <= n - m; r++) {
    for (int c = 0; c <= n - m; c++) {
      if (a[r][c] == b[0][0]) {
        ans = true;
        for (int rb = r; rb < r + m; rb++) {
          bool unfit = false;
          for (int cb = c; cb < c + m; cb++) {
            if (a[rb][cb] != b[rb - r][cb -c]) {
              unfit = true;
              break;
            }
          }
          if (unfit) {
            ans = false;
            break;
          }
        }
        if (ans) break;
      }
    }
    if (ans) break;
  }
  
  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}
