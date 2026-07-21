#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  vector<string> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  string ans = "No";
  for (int i = 0; i <= n - m; i++) {
    for (int j = 0; j <= n - m; j++) {
      bool check = true;
      for (int x = 0; x < m; x++) {
        for (int y = 0; y < m; y++) {
          char pa = a[i + x][j + y];
          char pb = b[x][y];

          if (pa != pb) {
            check = false;
            break;
          }
        }

        if (!check) break;
      }

      if (check) {
        ans = "Yes";
        i = n;
        break;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
