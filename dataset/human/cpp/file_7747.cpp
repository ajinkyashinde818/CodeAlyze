#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  long long int sum=0,sum2=0,ans=999999999999;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    sum+=a[i];
  }
  sum2=a[0];
  ans=min(ans,abs(sum-2*sum2));
  for(int i=1;i<n-1;i++)
  {
    sum2+=a[i];
    ans=min(ans,abs(sum-2*sum2));
  }
  cout<<ans;
}
