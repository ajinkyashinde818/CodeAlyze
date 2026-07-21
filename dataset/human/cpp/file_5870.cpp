#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=100005;

int n;
LL m,v[N],mx[N],x[N];

int main()
{
	scanf("%d%lld",&n,&m);LL ans=0;
	for (int i=1;i<=n;i++) scanf("%lld%lld",&x[i],&v[i]),v[i]+=v[i-1];
	for (int i=1;i<=n;i++) ans=std::max(ans,v[i]-x[i]),ans=std::max(ans,v[n]-v[i-1]-m+x[i]);
	for (int i=n;i>=1;i--) mx[i]=std::max(mx[i+1],v[n]-v[i-1]-m+x[i]);
	for (int i=1;i<=n;i++) ans=std::max(ans,v[i]-x[i]*2+mx[i+1]);
	for (int i=1;i<=n;i++) mx[i]=std::max(mx[i-1],v[i]-x[i]);
	for (int i=n;i>=1;i--) ans=std::max(ans,v[n]-v[i-1]-(m-x[i])*2+mx[i-1]);
	printf("%lld",ans);
	return 0;
}
