#include<bits/stdc++.h>
using namespace std;
signed main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;cin>>n;
  long long ans;
  vector<long long> a(n),r(n+1),l(n+1);
  r[0]=0;l[n]=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    r[i+1]=a[i]+r[i];
  }
  for(int i=n-1;i>=0;i--){
    l[i]=l[i+1]+a[i];
  }
  ans=abs(r[1]-l[1]);
  for(int i=1;i<n;i++){
    if(abs(r[i]-l[i])<ans){ans=abs(r[i]-l[i]);}
  }
  cout<<ans;
}
