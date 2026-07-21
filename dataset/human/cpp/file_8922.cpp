#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,m;cin>>n>>m;
  bool ans=false;
  string a[n+1],b[m+1];
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<m;i++) cin>>b[i];
  for(int i=0;i<n-m+1;i++){
      for(int j=0;j<n-m+1;j++){
          bool flag=true;
          for(int k=0;k<m;k++){
              for(int l=0;l<m;l++){
                  if(a[i+k][j+l]!=b[k][l]) flag=false;
              }
          }
          ans=(ans || flag);
      }
  }
  if(ans)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
