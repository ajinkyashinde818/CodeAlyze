#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
long long w[101010];
long long x[101010],mx[101010],mx2[101010];
int main()
{
	int n,i;
	long long c,sum,tmp,ans;
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%lld",&n,&c);
	for(i=1;i<=n;i++)
		scanf("%lld%lld",&x[i],&w[i]); 
	x[n+1]=c;
	tmp=0;
	for(i=n;i>=1;i--)
	{
		tmp=tmp-(x[i+1]-x[i])+w[i];
		mx[i]=max(mx[i+1],tmp);
		mx2[i]=max(mx2[i+1],tmp-(c-x[i]));
//		printf("%d %lld\n",i,mx[i]);
	}
	ans=mx[1];
	sum=0;
	for(i=1;i<=n;i++)
	{
		sum=sum-(x[i]-x[i-1])+w[i];
//		printf("%d %lld %lld\n",i,sum,mx[i+1]);
		ans=max(ans,sum);
		ans=max(ans,sum+mx2[i+1]);
		ans=max(ans,sum+mx[i+1]-x[i]);
	}
	printf("%lld\n",ans);
 	return 0;
}
