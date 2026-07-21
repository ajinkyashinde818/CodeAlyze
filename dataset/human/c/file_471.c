#include<stdio.h>
#include<math.h>
long long num[200000+50];
typedef long long ll;
int main()
{
	ll n;
	while(scanf("%lld",&n)!=EOF)
	{
		ll i,sn=0;
		ll k;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&num[i]);
			sn+=num[i];
		}
		k=fabs(sn-2*num[0]);
		for(i=0;i<n-1;i++)
		{
			sn-=2*num[i];
			if(k>fabs(sn))
			k=fabs(sn);
		}
		if(k<0)
		k*=-1;
		printf("%lld\n",k);
	}
}
