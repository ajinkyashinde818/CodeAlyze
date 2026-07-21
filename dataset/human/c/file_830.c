#include<stdio.h>
#include<string.h>
int a[51],b[51],n,maxmin=0x7fffffff,maxmax,dp[51],num;
long long ans;
bool flag,bjuse[51];
bool check()
{
	for(int i=1;i<=n;i++)
	{
		memset(dp,0,sizeof(dp));
		dp[a[i]]=1;
		flag=0;
		for(int j=50;j>=1;j--)
			if(bjuse[j])
				for(int k=j;k<=50;k++)
					if(dp[k])
					{
						dp[k%j]=1;
						if(k%j==b[i])
						{
							flag=1;
							break;
						}
					}
		if(!flag&&!dp[b[i]])return 0;
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=50;i++)
		bjuse[i]=1;
	if(!check())
	{
		printf("-1");
		return 0;
	}
	for(int i=50;i>=1;i--)
	{
		bjuse[i]=0;
		if(!check())bjuse[i]=1;	
	}
	for(int i=1;i<=50;i++)
		if(bjuse[i])ans|=1ll<<i;
	printf("%lld",ans);
	return 0;
}
