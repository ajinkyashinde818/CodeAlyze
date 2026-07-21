#include <iostream>
#include <vector>
using namespace std;
int a[50][50], b[50][50];
int main(void) {
  int n, m;
  cin >> n >> m;
  vector<string> a(n), b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  bool ans = 0;
  for (int i = 0; i <= n - m; i++) {
    for (int j = 0; j <= n - m; j++) {
      bool f = 1;
      for (int k = 0; k < m; k++) {
        for (int l = 0; l < m; l++) {
          if (a[i + k][j + l] != b[k][l]) f = 0;
        }
      }
      if (f) ans = 1;
    }
  }
  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
