#include <stdio.h>

int main(void) {
	int N,M;
	scanf("%d%d",&N,&M);
	long long int dp[N+1];
	int s[N+1];
	for(int i=0;i<N+1;i++) s[i] = 1;
	for(int i=0;i<M;i++){
		int a;
		scanf("%d",&a);
		s[a] = 0;
	}
	dp[0] = 1; dp[1] = 1*s[1];
	for(int i=2;i<N+1;i++){
		dp[i] = ((dp[i-1]+dp[i-2])*s[i])%1000000007;
	}
		printf("%d",dp[N]%1000000007);
		
	/*for(int i=0;i<=N;i++){
		printf("%d %d\n",dp[i],s[i]);
	}*/
	
	return 0;
}
