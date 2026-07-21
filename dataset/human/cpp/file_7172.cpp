#include <bits/stdc++.h>
using namespace std;
int n;
long long a,sum[200000];
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a;
    if(i)sum[i]=sum[i-1]+a;
    else sum[i]=a;
  }
  long long ans=20000000000;
  for(int i=0;i<n-1;i++){
    ans=min(ans,abs(sum[n-1]-2*sum[i]));
  }
  cout<<ans;
}
