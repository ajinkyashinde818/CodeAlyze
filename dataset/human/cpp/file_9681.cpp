#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m; cin>>n>>m;  
  vector<string>A(n);
  vector<string>B(m);
  for(int i=0;i<n;i++){
    cin>>A[i];
  }
  for(int i=0;i<m;i++){
    cin>>B[i];
  }  
  vector<int>ans;
  for(int i=0;i<n-m+1;i++){
    for(int j=0;j<n-m+1;j++){
      int flag=1;
      for(int k=0;k<m;k++){
        string t=A[i+k].substr(j,m);
        if(t==B[k]) continue;
        else{
          flag=0;
          break;
        }
      }
      if(flag==1) ans.push_back(flag);
    }
  }
  if(ans.size()>0) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
