#include<bits/stdc++.h>
using namespace std;
int main(){
  long long int n,a[222222],ans=LLONG_MAX;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    a[i]+=a[i-1];
  }
  for(int i=1;i<n;i++) ans=min(ans,llabs(a[i]-(a[n]-a[i])));
  cout<<ans<<endl;
  return(0);
}
