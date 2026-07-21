#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define lli long long int

#define MOD 1000000007
int main(void)
{
	lli n,m;
	scanf("%lld %lld",&n, &m);
	lli i, j, k;
	i = 0;
	j = 0;
	k = 0;
	lli *a;
	a = (lli *)malloc(sizeof(lli)*(n+2));
	while (i < m)
	{
		scanf("%lld",&(a[i]));
		i++;
	}
	i = 0;
	lli *dp;
	dp = (lli *)malloc(sizeof(lli)*(n+2));
	dp[0] = 1;
	dp[1] = 1;
	j = 0;
	if(a[0] == 1)
	{
		dp[1] = 0;
		j++;
	}
	i = 2;
	while (i <= n)
	{
		dp[i] = (dp[i-1]%MOD+dp[i-2]%MOD)%MOD;
		if(a[j] == i)
		{
			dp[i] = 0;
			j++;
		}
		//printf("debug i:%lld, j:%lld, dp:%lld\n",i, j, dp[i]);
		i++;
	}
	printf("%lld\n",dp[n]);
	return (0);
}
