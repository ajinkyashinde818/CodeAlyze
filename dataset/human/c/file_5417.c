#include<stdio.h>
unsigned char dp[190][190][190][20];
char s[190][190];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",s[i]);
	}
	for(int i=n-1;i>=0;i--)
	{
		for(int j=m-1;j>=0;j--)
		{
			bool ok0=true;
			for(int k=j;k<m;k++)
			{
				if(s[i][k]!=s[i][j])
				{
					ok0=false;
				}
				if(!ok0)
				{
					dp[i][j][k][0]=0;
				}
				else if(s[i][j]==s[i+1][j])
				{
					dp[i][j][k][0]=dp[i+1][j][k][0]+1;
				}
				else
				{
					dp[i][j][k][0]=1;
				}
			}
			for(int k=1;k<=16;k++)
			{
				int now=j;
				for(int l=j;l<m;l++)
				{
					dp[i][j][l][k]=0;
					if(dp[i][j][l][k-1])
					{
						dp[i][j][l][k]=dp[i][j][l][k-1]+dp[i+dp[i][j][l][k-1]][j][l][k-1];
					}
					while(now<l&&dp[i][j][now][k-1]>dp[i][now+1][l][k-1])
					{
						now++;
					}
					if(now<l&&dp[i][j][now][k-1]>dp[i][j][l][k])
					{
						dp[i][j][l][k]=dp[i][j][now][k-1];
					}
					if(now>j&&dp[i][now][l][k-1]>dp[i][j][l][k])
					{
						dp[i][j][l][k]=dp[i][now][l][k-1];
					}
				}
			}
		}
	}
	for(int i=0;i<=16;i++)
	{
		if(dp[0][0][m-1][i]>=n)
		{
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}
