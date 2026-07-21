#include<iostream>
#include<cstdio>
#include<cstring>

template<typename T>inline void check_max(T a,T &b){if(a>b)b=a;}

namespace o_o
{
	typedef long long ll;
	const int N=101000;

	ll x[N],w[N];

	int n;
	ll m;


	ll f[N],g[N];

	void solve()
	{
		scanf("%d%lld",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%lld%lld",x+i,w+i);
		for(int i=1;i<=n;i++)
			w[i]+=w[i-1];

		for(int v=1;v<=n;v++)
		{
			f[v]=x[v]-w[v-1];
			g[v]=(-w[v-1]-(m-x[v])*2);
		}
		for(int i=n;i;i--)check_max(f[i],f[i-1]),check_max(g[i],g[i-1]);


		ll ans=0;
		for(int i=1;i<=n;i++)
			check_max(w[i]-x[i],ans);
		for(int i=1;i<=n;i++)
			check_max(w[n]-w[i-1]-(m-x[i]),ans);


		for(int u=1;u<n;u++)
		{
			check_max((w[u]+w[n]-x[u]*2-m)+f[u+1],ans);
			check_max(w[u]+w[n]-x[u]+g[u+1],ans);
		}

		printf("%lld\n",ans);
	}
}

int main()
{
	o_o::solve();
	return 0;
}
