#include <stdio.h>

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	int a[M], brk[N+1];
	long long int dp[N+1];
	int i;

	for (i = 0; i < N+1; i++) 
		brk[i] = 0;

	for (i = 0; i < M; i++) {
		scanf("%d", &a[i]);
		brk[a[i]] = 1;
	}
	
//	for (i = 0; i < M; i++)
//		printf("a[%d] = %d\n", i, a[i]);

//	for (i = 0; i < N + 1; i++)
//		printf("brk[%d] = %d\n", i, brk[i]);
	
	dp[0] = 1;
	brk[0] = 0;
	if (brk[1] == 1) 
		dp[1] = 0;
	else 
		dp[1] = 1;
//	printf("dp[%d] = %lld\n", 0, dp[0]);
//	printf("dp[%d] = %lld\n", 1, dp[1]);
//	printf("dp[%d] = %lld\n", 2, dp[2]);
	for (i = 2; i < N + 1; i++) {
		if (brk[i] == 1) {
			dp[i] = 0;
		} else {
			dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
		}
//		printf("dp[%d] = %lld\n", i, dp[i]);
	}

	printf("%lld\n", dp[i-1]);

	return 0;
}
