#include <stdio.h>

int main()
{
	int i, N, K;
	long long a[1001];
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) scanf("%lld", &(a[i]));

	int j, k, count;
	long long ans = 0, sum[1001][1001], bit[60];
	for (i = 1, bit[0] = 1; i < 60; i++) bit[i] = bit[i-1] << 1;
	for (i = 1; i <= N; i++) {
		for (j = i, sum[i][i-1] = 0; j <= N; j++) sum[i][j] = sum[i][j-1] + a[j];
	}
	for (k = 59; (sum[1][N] | bit[k]) != sum[1][N]; k--);
	for (; k >= 0; k--) {
		count = 0;
		for (i = 1; i <= N; i++) {
			for (j = i; j <= N; j++) if ((sum[i][j] | bit[k]) == sum[i][j]) count++;
		}
		if (count >= K) {
			ans += bit[k];
			for (i = 1; i <= N; i++) {
				for (j = i; j <= N; j++) if ((sum[i][j] | bit[k]) != sum[i][j]) sum[i][j] = 0;
			}
		}
	}
	
	printf("%lld\n", ans);
	fflush(stdout);
	return 0;
}
