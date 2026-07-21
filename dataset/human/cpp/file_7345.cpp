#include <bits/stdc++.h>
using namespace std;
int main(){
  int n; cin>>n;
  long long a,sum[200000];
  long long ans=20000000000;
  for(int i=0;i<n;i++){
    cin>>a;
    sum[i]=a;
    if(i)sum[i]+=sum[i-1];
  }
  for(int i=0;i<n-1;i++){
    ans=min(ans,abs(sum[n-1]-2*sum[i]));
  }
  cout<<ans;
}
