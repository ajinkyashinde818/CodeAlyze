#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n+1, vector<char>(n+1,'z'));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) cin >> a[i][j];
  }
  vector<vector<char>> b(m+1, vector<char>(m+1,'z'));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) cin >> b[i][j];
  }
  
  for (int i = 0; i <= n-m; i++) {
    for (int j = 0; j <= n-m; j++) {
      for (int h = 1; h <= m; h++) {
        int judge = 0;
        for (int w = 1; w <= m; w++) {
          if (a[i+h][j+w] != b[h][w]) {
            judge = 1;
            break;
          }
          if (h == m && w == m) {
            cout << "Yes" << endl;
            return 0;
          }
        }
        if (judge == 1) break;
      }
    }
  }
  
  cout << "No" << endl;
}
