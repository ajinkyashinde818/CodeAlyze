#include <stdio.h>

const int bit[17] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536};
int N, a[17][17];
long long dp[65536], sum[65536];

long long recursion(int n)
{
	if (dp[n] >= 0) return dp[n];
	else dp[n] = sum[n];
	
	int i, j, k, m, b[17];
	long long tmp;
	for (i = 0, m = 0; i < N; i++) if ((n & bit[i]) == bit[i]) b[m++] = i;
	k = bit[b[0]];
	while (k < bit[b[m-1]]) {
		tmp = recursion(k) + recursion(n ^ k);
		if (tmp > dp[n]) dp[n] = tmp;
		for (i = 0; (k & bit[b[i]]) != 0; i++);
		for (k ^= bit[b[i--]]; i >= 0; k ^= bit[b[i--]]);
	}
	return dp[n];
}
 
int main()
{
	int i, j, k;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) scanf("%d", &(a[i][j]));
	}
	for (i = 1, dp[0] = 0; i < bit[N]; i++) dp[i] = -1;
	for (k = 0; k < bit[N]; k++) {
		for (i = 0, sum[k] = 0; i < N; i++) {
			if ((k & bit[i]) == 0) continue;
			for (j = i + 1; j < N; j++) if ((k & bit[j]) != 0) sum[k] += a[i][j];
		}
	}
	printf("%lld\n", recursion(bit[N] - 1));
	fflush(stdout);
	return 0;
}
