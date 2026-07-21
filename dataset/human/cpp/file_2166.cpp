#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib> 
using namespace std;

long long  dp[2][100005];
long long a[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=0;i<100004;i++)
	{
		dp[0][i]=-1e18;
		dp[1][i]=-1e18;
	}
	dp[0][1]=a[1];
	for(int i=2;i<=n;i++)
	{
		dp[0][i]=max(dp[0][i-1],dp[1][i-1])+a[i];
		dp[1][i]=max(dp[0][i-1]-2*a[i-1]-a[i],dp[1][i-1]+2*a[i-1]-a[i]);
	}
	printf("%lld\n",max(dp[0][n],dp[1][n]));
	
	
	return 0;
}
