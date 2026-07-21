#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(void){
  int n,m,i,j,k,l;
  string a[55],b[55];
  cin >> n >> m;
  for (i=0;i<n;i++) cin >> a[i];
  for (j=0;j<m;j++) cin >> b[j];
  for (i=0;i<=n-m;i++){
    for (j=0;j<=n-m;j++){
      for (k=0;k<m;k++){
        for (l=0;l<m;l++) if (a[i+k][j+l]!=b[k][l]) break;
        if (l!=m) break;
      }
      if (k==m) break;
    }
    if (j!=n-m+1) break;
  }
  if (i!=n-m+1) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
