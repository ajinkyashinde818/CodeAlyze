#include <bits/stdc++.h>
using namespace std; 

char a[55][55], b[55][55];

int main() {
  int n, m;
  cin >> n >> m;
  
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  
  for (int p = 0; p <= n - m; p++)
    for (int q = 0; q <= n - m; q++) {
      bool ok = true;
      for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
          ok &= a[p + i][q + j] == b[i][j];
      if (ok) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  
  cout << "No" << endl;
}
