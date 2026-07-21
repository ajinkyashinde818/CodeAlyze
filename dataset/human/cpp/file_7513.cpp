#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
int main(){
  int n;cin>>n;
  long s=0,a,ans=LONG_MAX;
  vector<int>v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  a=accumulate(v.begin(),v.end(),0L);
  for(int i=0;i<n-1;i++)s+=v[i],a-=v[i],ans=min(ans,labs(s-a));
  cout<<ans<<endl;
  return 0;
}
