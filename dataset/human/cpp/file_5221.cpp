#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll  powFac(ll a,ll b,ll m)
{
  ll temp1=1, ans=1;
  if(a<0)temp1=0;
  else {
  for(ll i=1;i<=a;i++)temp1=temp1*i%m;
}
   while(b>0)
   {
    if(b&1)ans=ans*temp1%m;
    temp1=temp1*temp1%m;
    b>>=1;
   }
 return ans;
} 




int main()
{
   
    ll i,j,n,r,flag=0,temp1=0,temp2=0,temp3=0,m=1000000007;
   cin>>n>>r;

  if(n>=10)
  {
    i=r;
  }
  else 
  {
    i=100*(10-n)+r;
  }

  cout<<i<<endl;

 return 0;
  }
