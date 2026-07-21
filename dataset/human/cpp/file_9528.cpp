#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  char c[n][n];
  char t[m][m];
  bool b=false;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>c[i][j];
    }
  }
  for(int i=0;i<m;i++){
    for(int j=0;j<m;j++){
      cin>>t[i][j];
    }
  }
  for(int i=0;i<=n-m;i++){
    for(int j=0;j<=n-m;j++){
      if(c[i][j]==t[0][0]){
        b=true;
        for(int k=0;k<m;k++){
          for(int l=0;l<m;l++){
            if(c[i+k][j+l]!=t[k][l]){
              b=false;
              break;
            }
          }
        }
        if(b){
          cout<<"Yes";
          return 0;
        }
      }
    }
  }
  cout<<"No";
}
