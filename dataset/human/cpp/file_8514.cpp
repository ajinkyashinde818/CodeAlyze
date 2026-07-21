#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char a[60][60], b[60][60];
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      cin >> a[i][j];
    }
  }
  for(int i=1; i<=m; i++){
    for(int j=1; j<=m; j++){
      cin >> b[i][j];
    }
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      int cnt = 0;
      if(a[i][j]==b[1][1]){
        cnt++;
        for(int k=1; k<m; k++){
          if(a[i][j+k]!=b[1][k+1]){
            break;
          }
          cnt++;
        }
      }
      if(cnt==m){
        for(int s=1; s<m; s++){
          for(int t=0; t<m; t++){
            if(a[i+s][j+t]!=b[s+1][t+1]) break;
            cnt++;
          }
        }
      }
      if(cnt==m*m) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
