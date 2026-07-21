#include<cstdio>
#include<vector>

using namespace std;

using ll=long long;
using vll=vector<ll>;

int max_u(ll&m, ll v)
{
	if(m<v)
	{
		m=v;
		return 1;
	}
	return 0;
}


void disp(vll&v)
{
	for(int i=0;i<v.size();i++)
	{
		printf("[%d]%lld ", i, v[i]);
	}
	printf("\n");
}


int main(void)
{
	int n;
	ll c;

	while(scanf("%d%lld", &n, &c)==2)
	{
		vector<ll> x(n+2), v(n+2), cw(n+2), ccw(n+2), rcw(n+2), rccw(n+2);
		ll ans=0;
		ll sum;

		x[0]=0;
		x[n+1]=c;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld", &x[i], &v[i]);
		}

		sum=0;
		for(int i=1;i<=n;i++)
		{
			sum+=v[i]-(x[i]-x[i-1]);
			cw[i]=max(cw[i-1], sum);
			rcw[i]=cw[i]-x[i];
		}
		sum=0;
		for(int i=1;i<=n;i++)
		{
			sum+=v[n+1-i]-(x[n+2-i]-x[n+1-i]);
			ccw[i]=max(ccw[i-1], sum);
			rccw[i]=ccw[i]-(c-x[n+1-i]);
		}
//		disp(cw);
//		disp(ccw);

		for(int i=1;i<=n;i++)
		{
			max_u(ans, cw[i]+rccw[n-i]);
			max_u(ans, ccw[i]+rcw[n-i]);
		}
		printf("%lld\n", ans);
	}

	return 0;
}
