#include<stdio.h>
#include<stdbool.h>
const int mod = 1e9 + 7;
int N, M, dp[1<<17] = {1};
bool A[1<<17] = {};
int main(){
	scanf("%d%d", &N, &M);
	while(M--){
		int a;
		scanf("%d", &a);
		A[a]++;
	}
	for(int i=1; i<=N; i++){
		if(i>1) dp[i] += dp[i-2];
		dp[i] += dp[i-1];
		dp[i] %= mod;
		if(A[i]) dp[i] = 0;
	}
	printf("%d\n", dp[N]);
	return 0;
}
