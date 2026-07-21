#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll MOD = 1000000007;
ll INFL = 1ll << 60;
ll INF = 1 << 30;
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
  int n, m;

  cin >> n >> m;
  string a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  string b[m];
  for (int i = 0; i < m; i++)
    cin >> b[i];

  for (int i = 0; i <= n - m + 1; i++) {
    for (int j = 0; j <= n - m + 1; j++) {
      bool can = true;
      for (int y = 0; y < m; y++) {
        for (int x = 0; x < m; x++) {
          if (a[i + y][j + x] != b[y][x])
            can = false;
        }
      }

      if (can) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
