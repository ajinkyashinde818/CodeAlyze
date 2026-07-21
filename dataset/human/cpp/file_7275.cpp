#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<long long>a(n);
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    if(i!=0)a[i]+=a[i-1];
  }
  long long ans=10000000000000;
  for(int i=0;i<n-1;i++)
  {
    ans=min(ans,abs(a[i]-(a[n-1]-a[i])));
  }
  cout<<ans<<endl;
  return 0;
}
