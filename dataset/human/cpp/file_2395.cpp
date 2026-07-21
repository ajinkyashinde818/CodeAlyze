#include<bits/stdc++.h>
using namespace std;
const int N=100010;
typedef long long ll;
int a[N];
int main()
{
  ll n,x,mi=INT_MAX,cnt=0,s=0;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    if(x<0) cnt++,s-=x;
    else s+=x;
    mi=min(mi,abs(x));
  }
  if(cnt&1) cout<<s-2*abs(mi)<<endl;
  else cout<<s<<endl;
  return 0;
}
