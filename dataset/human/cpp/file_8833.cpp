#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(int argc, char *argv[]) { ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int n,m;cin>>n>>m;
vector<string> A(n),B(m);
for(int i=0;i<n;i++){
cin>>A[i];
}
for(int i=0;i<m;i++){
cin>>B[i];
}
for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
    bool ok=true;
    for(int k=0;k<m;k++){
      if(i+k>=n || j+m>n){
        ok=false;
        break;
      }
      string a = A[i+k].substr(j, m);
      string b = B[k];
      if (a != b)ok=false;
    }
    if(ok){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
}
      cout<<"No"<<endl;
  
  return 0;
}
