#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  vector<string> a(n),b(m);
  for(int i=0; i<n; i++)cin>>a[i];
  for(int i=0; i<m; i++)cin>>b[i];

  bool ans=false;
  for(int i=0; i<=n-m; i++){
    for(int j=0; j<=n-m; j++){
      bool eq=true;
      for(int k=0; k<m; k++){
        if(a[i+k].substr(j,m)!=b[k]){
          eq=false;
          break;
        }
      }
      if(eq){
        ans=true;
        break;
      }
    }
  }

  if(ans)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
