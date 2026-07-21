#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n, m;
  cin >> n >> m;

  char A[n][n];
  memset(A, 0, sizeof(A));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cin >> A[i][j];
  }

  char B[m][m];
  memset(B, 0, sizeof(B));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) cin >> B[i][j];
  }

  for (int i = 0; i < (n + 1) - m; ++i) {
    for (int j = 0; j < (n + 1) - m; ++j) {
      bool match_found = true;

      for (int x = 0; x < m && match_found; ++x) {
        for (int y = 0; y < m && match_found; ++y) {
          if (A[i + x][j + y] != B[x][y]) match_found = false;
        }
      }

      if (match_found) {
        cout << "Yes" << "\n";
        return 0;
      }
    }
  }

  cout << "No" << "\n";
}
