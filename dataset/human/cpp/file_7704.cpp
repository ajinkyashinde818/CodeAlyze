#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
long long ans=66666666666666LL,a[500001];
long long getabs(long long x)
{
	return x>0?x:-x;
}
int main()
{
	long long i,n,k;
	a[0]=0;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[i]=k+a[i-1];
	}
	for(i=1;i<n;i++)
		ans=min(ans,getabs(a[n]-2*a[i]));
	printf("%lld",ans);
	return 0;
}
