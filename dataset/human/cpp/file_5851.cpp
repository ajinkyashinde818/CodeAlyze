#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const LL N=100005;
LL x[N],v[N];
LL f[N];//正着走走到第i个的收益
LL g[N];//倒着走走到第i个的收益 
int main()
{
	LL n,c;
	scanf("%lld%lld",&n,&c);
	for (LL u=1;u<=n;u++)	scanf("%lld%lld",&x[u],&v[u]);
	LL now=0,lalal=0;
	LL ans=0;
	for (LL u=1;u<=n;u++)	{lalal=lalal+v[u]-(x[u]-now);now=x[u];f[u]=lalal;ans=max(ans,f[u]);}
	now=c,lalal=0;
	for (LL u=n;u>=1;u--)	{lalal=lalal+v[u]-(now-x[u]);now=x[u];g[u]=lalal;ans=max(ans,g[u]);}
	//printf("%lld\n",ans);
	LL mx=0;
	for (LL u=n-1;u>=1;u--)	
	{
		mx=max(mx,g[u+1]);
		ans=max(ans,mx+f[u]-x[u]);
	}
	mx=0;
	for (LL u=2;u<=n;u++)
	{
		mx=max(mx,f[u-1]);
		ans=max(ans,g[u]+mx-(c-x[u]));
	}
	printf("%lld\n",ans);
	return 0;
}
