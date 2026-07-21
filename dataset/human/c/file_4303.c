#include <stdio.h>

int main()
{
	int i, N, M, a[100001];
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) scanf("%d", &(a[i]));
	
	long long j, dp[3] = {1};
	for (i = 1, j = 1; i <= N; i++) {
		if (a[j] == i) {
			j++;
			dp[i%3] = 0;
		} else dp[i%3] = (dp[(i+1)%3] + dp[(i+2)%3]) % 1000000007;
	}
	printf("%lld\n", dp[N%3]);
	fflush(stdout);
	return 0;
}
