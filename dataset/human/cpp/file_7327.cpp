#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,a,i,ans=1e18;
  cin>>n;
  vector<int64_t> b(n+1);
  for(i=0;i<n;i++){
    cin>>a;
    b.at(i+1)=b.at(i)+a;
  }
  for(i=1;i<n;i++) ans=min(ans,abs(b.at(n)-2*b.at(i)));
  cout<<ans<<endl;
}
