#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  long long a[n],sum=0,ans=INT_MAX,snuke=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
  }
  for(int i=0;i<n-1;i++){
    snuke+=a[i];
    ans=min(abs(sum-2*snuke),ans);
  }
  cout<<ans<<endl;
}
