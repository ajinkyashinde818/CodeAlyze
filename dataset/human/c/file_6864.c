#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int main(void) {
	int i, j, k;
	int n;
	int sum[101] = {0}, dp[101][101] = {0}, max;

	scanf("%d", &n);

	max = -10000;
	for (i = 0; i < n; i++) {
		for (j = 1; j <= n; j++) {
			int a;
			scanf("%d", &a);
			sum[j] = sum[j - 1] + a;
		}

		for (j = 1; j <= n; j++)
			for (k = j; k <= n; k++) {
				dp[j][k] = max(dp[j][k] + sum[k] - sum[j - 1], sum[k] - sum[j - 1]);
				max = max(max, dp[j][k]);
			}
	}

	printf("%d\n", max);

	return 0;
}
