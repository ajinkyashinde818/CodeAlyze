#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  char a[n][n], b[m][m];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++) cin >> a[i][j];
  }
  for(int i = 0; i < m; i++){
    for(int j = 0; j < m; j++) cin >> b[i][j];
  }
  
  bool exist = false;
  for(int sy = 0; sy < n-m+1; sy++){
    for(int sx = 0; sx < n-m+1; sx++){
      bool match = true;
      for(int y = 0; y < m; y++){
        for(int x = 0; x < m; x++){
          if(b[y][x] != a[sy+y][sx+x]) match = false;
        }
      }
      if(match) exist = true;
    }
  }
  
  if(exist) cout << "Yes" << endl;
  else cout << "No" << endl;
}
