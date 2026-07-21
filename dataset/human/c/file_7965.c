#include <stdio.h>

int main()
{
	int N, K, C;
	char S[200001];
	scanf("%d %d %d", &N, &K, &C);
	scanf("%s", S);
	
	int i, k, dp[200002] = {};
	for (i = N, k = N * 2 + 1, dp[N+1] = 0; i >= 1; i--) {
		if (S[i-1] == 'o' && i + C < k) {
			dp[i] = dp[i+1] + 1;
			k = i;
		} else dp[i] = dp[i+1];
	}
	if (dp[1] > K) return 0;

	for (i = 1; i <= N; i++) {
		if (dp[i] > dp[i+1]) {
			printf("%d\n", i);
			i += C;
		} else if (S[i-1] == 'o') {
			for (k = i; k <= N && dp[k+1] == dp[i]; k++);
			i = (k > i + C)? k: i + C;
		} 
	}
	fflush(stdout);
	return 0;
}
