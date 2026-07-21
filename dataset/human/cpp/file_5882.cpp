#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 100010;
inline LL read()
{
  LL p=0; LL f=1; char ch=getchar();
  while(ch<'0' || ch>'9'){if(ch=='-') f=-1; ch=getchar();}
  while(ch>='0' && ch<='9'){p=p*10+ch-'0'; ch=getchar();}
  return p*f;
}

LL n,c; LL a[N],sum[N],mx[N]; LL val[N];

LL ans = 0;

void solve()
{
  memset(mx,0,sizeof(mx));
  memset(sum,0,sizeof(sum));
  LL s = 0; for(LL i=n;i>=1;i--)
  {
    s += val[i]; mx[i] = max(mx[i-1] , max(0ll , s - 2 * (c-a[i])));
  }
  s = 0;
  for(LL i=1;i<=n;i++)
  {
    s += val[i]; sum[i] = max(sum[i-1],max(0ll,s-a[i]));
    ans = max(ans , sum[i] + mx[i+1]);
    // printf("%lld %lld %lld\n",i,sum[i],mx[i+1]);
  }
}

int main()
{
  n = read(); c = read();
  for(LL i=1;i<=n;i++) a[i] = read(),val[i] = read();
  solve();
  for(LL i=1;i<=n;i++) a[i] = c - a[i];
  reverse(a+1,a+n+1); reverse(val+1,val+n+1);
  solve();
  return printf("%lld\n",ans),0;
}
