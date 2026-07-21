#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
long long x[101010],v[101010];
long long sum1[101010],sum2[101010];
long long ma1[101010],ma2[101010];
int main()
{
	int n;
	long long c;
	long long ans=0;
	scanf("%d%lld",&n,&c);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&x[i],&v[i]);
	sum1[0]=sum2[n+1]=0;
	for(int i=1;i<=n;i++)
		sum1[i]=sum1[i-1]+v[i];
	for(int i=n;i>=1;i--)
		sum2[i]=sum2[i+1]+v[i];
	ma1[1]=sum1[1]-x[1];
	ma2[n]=sum2[n]-c+x[n];
	for(int i=2;i<=n;i++)
		ma1[i]=max(ma1[i-1],sum1[i]-x[i]);
	for(int i=n-1;i>=1;i--)
		ma2[i]=max(ma2[i+1],sum2[i]-c+x[i]);
	ans=max(ma1[n],ma2[1]);
	for(int i=1;i<n;i++)
		ans=max(ans,sum1[i]+ma2[i+1]-x[i]*2);
	for(int i=n;i>1;i--)
		ans=max(ans,sum2[i]+ma1[i-1]-(c-x[i])*2);
	printf("%lld",max((long long)0,ans));
	return 0;
}
