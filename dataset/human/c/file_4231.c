#include<stdio.h>
int n,t,i,j,dp[100005],f[100005]={0};
int main()
{
	dp[0]=1;
	scanf("%d%d",&n,&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&j);
		f[j]=1;
	}
	for(i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
			if(i>=2)
			dp[i]=dp[i-1]+dp[i-2];
			else if(i==1)
			dp[i]=dp[i-1];
		}
		else
		{
			dp[i]=0;
		}
		dp[i]%=1000000007;
	}
	printf("%d",dp[n]);
}
