#include <stdio.h>
#define MOD 1000000007

int doubleup(int num,int goal);

int main()
{
	int n,m,k;
	int i,j;
	int ans=0;
	int step[100010]={0};
	int dp[100010]={0};
	
	scanf("%d %d",&n,&m);
	
	for(i=0;i<m;i++)
	{
		scanf("%d",&k);
		step[k]=1;//1は壊れた床
	}
	
	
	for(j=0;j<=n;j++)
	{
		if(step[j])dp[j]=0;
		else if(j==0||j==1)dp[j]=1;
		else dp[j]=(dp[j-1]+dp[j-2])%MOD;
	}
	
	printf("%d",dp[n]);
	return 0;
}
