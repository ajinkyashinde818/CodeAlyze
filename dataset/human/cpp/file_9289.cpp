#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;

int main() {
  int n,m;
  cin>>n>>m;
  string a[n],b[m];
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<m;i++) cin>>b[i];
  bool ans=false;
  for(int i=0;i<=n-m;i++){
    for(int j=0;j<=n-m;j++){
      int cnt=0;
      for(int k=0;k<m;k++){
        if(b[k]==a[i+k].substr(j,m)) cnt++;
      }
      if(cnt==m) {
        ans=true;
        break;
      }
    }
    if(ans) break;
  }
  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
