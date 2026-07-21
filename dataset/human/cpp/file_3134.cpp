#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int ar[100005];

int main()
{
  ll n, i, ans, cnt=0, sum=0;

  cin>>n;

  for(i=0; i<n; i++)
  {
    cin>>ar[i];
    if(ar[i]<0)
    {
      cnt++;
      ar[i]=ar[i]*-1;
    }
  }
  sort(ar,ar+n);

  if(cnt%2==1)
  {
   ar[0]=ar[0]*-1;
  }

  for(i=0; i<n; i++)
  {
    sum+=ar[i];
  }

  cout<<sum<<endl;
}
