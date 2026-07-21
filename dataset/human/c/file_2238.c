#include <stdio.h>

int main(void)
{
	static char data[1001];
	static int dp[1000][1000];
	int n;
	int i,j;
	int maxdp;
	
	for(;;){
		maxdp=0;
		scanf("%d",&n);
		if(n==0) break;
		
		for(i=0;i<n;i++){
			scanf("%s",data);
			
			if(data[0]=='*') dp[i][0]=0;
			else dp[i][0]=1;
			
			if(i==0){
				for(j=1;j<n;j++){
					if(data[j]=='*') dp[0][j]=0;
					else dp[0][j]=1;
				}
			} else {
				for(j=1;j<n;j++){
					if(data[j]=='*'){
						dp[i][j]=0;
						continue;
					}
					
					dp[i][j]=dp[i-1][j];
					if(dp[i][j]>dp[i][j-1]) dp[i][j]=dp[i][j-1];
					if(dp[i][j]>dp[i-1][j-1]) dp[i][j]=dp[i-1][j-1];
					dp[i][j]++;
					
					if(maxdp<dp[i][j]) maxdp=dp[i][j];
				}
			}
			
		
		}
		
		
		printf("%d\n",maxdp);
		
		
	}
	
	return 0;
}
