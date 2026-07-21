#include <stdio.h>

int main(){
	int N,M,j=0;
	long long int mod=1000000007;
	scanf("%d%d",&N,&M);
	int a[M];
	long long int dp[N+1];
	for(int i=0;i<M;i++){
		scanf("%d",&a[i]);
	}
	dp[0]=0;
	for(int i=1;i<=N;i++){
		if(a[j]==i){
			//printf("a[%d]==%d\n",j,i);
			dp[i]=0;
			j++;
		}else if(i==1)dp[1]=1;
		else if(i==2 && dp[1]==1)dp[2]=2%mod;
		else if(i==2 && dp[1]==0)dp[2]=1%mod;
		else dp[i]=(dp[i-1]+dp[i-2])%mod;
		//printf("dp[%d]=%lld\n",i,dp[i]);
	}
	printf("%lld\n",dp[N]);
	return 0;
}
