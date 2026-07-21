#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,t,i;
  long long ans=0;
  cin>>n;
  vector<int>a(n);
  for(i=0;i<n;i++)cin>>a[i];
  for(i=0;i<n;i++){
    if(a[i]<1)t++;
    a[i]=abs(a[i]);
    ans+=a[i];
  }
  sort(a.begin(),a.end());
  if(t%2!=0)ans-=2*a[0];
  cout<<ans<<endl;
}
