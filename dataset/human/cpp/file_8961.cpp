#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<string> N(n);
  vector<string> M(m);
  for(int i=0;i<n;i++){
    cin>>N[i];
  }
  for(int i=0;i<m;i++){
    cin>>M[i];
  }
  string ans="No";
  
  for(int i=0;i+m<=n;i++){
    for(int j=0;j+m<=n;j++){
      bool b=true;
      for(int k=0;k<m;k++){
        if(N[i+k].substr(j,m)!=M[k]){b=false;continue;}
      }
      if(b){ans="Yes"; break;}
    }
  }
  cout<<ans;
}
