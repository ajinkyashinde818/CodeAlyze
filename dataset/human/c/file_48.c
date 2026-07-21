#include <stdio.h>

int main(void) {
	// your code goes here
	int r[3],n;

	scanf("%d%d%d%d",&r[0],&r[1],&r[2],&n);
	int i,dp[n+1];
	for(i=0;i<n+1;i++)
		dp[i] = 0;
	dp[0] = 1;
	int j;
	for(i=0;i<3;i++)
		for(j=r[i];j<=n;j++)
			dp[j] = dp[j] + dp[j - r[i]];
	printf("%d\n",dp[n]);
	return 0;
}
