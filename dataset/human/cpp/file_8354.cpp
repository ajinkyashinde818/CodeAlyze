#include<bits/stdc++.h>
using namespace std;
signed main(){
  int n,m,q;
  string a[100],b[100];
  cin>>n>>m;
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<m;i++) cin>>b[i];
  for(int i=0;i<=n-m;i++){
    for(int j=0;j<=n-m;j++){
      q=1;
      for(int k=0;k<m;k++){
        for(int l=0;l<m;l++){
          if(a[i+k][j+l]!=b[k][l]) q=0;
        }
      }
      if(q){
        cout<<"Yes\n";
        return 0;
      }
    }
  }
  cout<<"No\n";
}
