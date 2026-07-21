#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;cin >> n >> m;
  char a[n+m][n+m],b[m][m];
  
  for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
      cin >> a[i][j];
    }
  }
  for(int i=0;i<m;++i){
    for(int j=0;j<m;++j){
      cin >> b[i][j];
    }
  }

  int z = 0;
  
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(a[i][j] == b[0][0]){
        for(int k=0;k<m;k++){
          for(int l=0;l<m;l++){
            if(a[i+k][j+l] != b[k][l])z += 1;
          }
        }
        if(z == 0){
          cout << "Yes" << endl;
          return 0;
        }
        z = 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
