#include<iostream>
using namespace std;
int main(){
  int n,m,i,j,k,l;cin >> n >> m;bool ans = false,sans;
  char a[n][n],b[m][m];
  for(i=0;i<n;i++){
    for(j=0;j<n;j++) cin >> a[i][j];
  }
  for(i=0;i<m;i++){
    for(j=0;j<m;j++) cin >> b[i][j];
  }
  for(i=0;i<=n-m;i++){
    for(j=0;j<=n-m;j++){
      sans = true;
      for(k=0;k<m;k++){
        for(l=0;l<m;l++){
          if(a[i+k][j+l]!=b[k][l]) sans = false;
        }
      }
      if(sans) ans = true;
    }
  }
  cout << ((ans) ? "Yes":"No") << endl;
}
