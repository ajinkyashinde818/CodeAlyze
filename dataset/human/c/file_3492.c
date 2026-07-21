#include<stdio.h>
typedef long long int ll;

int main()
{
	ll n,k;
	scanf("%lld %lld",&n,&k);
	ll array[n+1],array1[n+1];
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&array[i]);
		array1[i]=0;
	}
	array1[1]=0;
	ll c=1,f1=0,f2=0;
	if(k<=n)
	{
		for(ll i=1;i<=k;i++)
		{
			c=array[c];
			if(array1[c]>0)
			{
				f2=array1[c];
				f1=i;
				i=n+1;
			}
			array1[c]=i;
		}
		printf("%lld\n",c);
	}
	else
	{
		for(ll i=1;i<=n;i++)
		{
			c=array[c];
			if(array1[c]>0)
			{
				f2=array1[c];
				f1=i;
				i=n+1;
			}
			array1[c]=i;
		}
		{
			ll cnt=c;
			if((k-f2+1)%(f1-f2)==0)
			{
				for(ll i=1;i<(f1-f2);i++)
					cnt=array[cnt];
			}
			else
			{
				for(ll i=2;i<=((k-f2+1)%(f1-f2));i++)
				{
					cnt=array[cnt];
				}
			}
			printf("%lld\n",cnt);
		}
	}
}
