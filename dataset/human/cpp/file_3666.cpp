#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  long long a,i,sum=0,c=0;
  long long mn=1e+10;
  for(i=0;i<n;i++)
  {
    cin>>a;
    sum+=abs(a);
    if(a<0) c++;
    mn=min(mn,abs(a));
  }
  if(c%2) cout<<sum-2*mn;
  else cout<<sum;
  return 0;
}
