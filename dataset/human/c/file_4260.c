/* Coached by rainboy */
#include <stdio.h>
#include <string.h>

#define N 100000
#define MD 1000000007

int main() {
	static char ok[N + 1];
	static int dp[N + 1];
	int n, m, i;

	scanf("%d%d", &n, &m);
	memset(ok, 1, sizeof ok);
	while (m--) {
		int a;

		scanf("%d", &a);
		ok[a] = 0;
	}
	dp[0] = 1;
	for (i = 1; i <= n; i++)
		if (ok[i])
			dp[i] = (dp[i - 1] + (i > 1 ? dp[i - 2] : 0)) % MD;
	printf("%d\n", dp[n]);
	return 0;
}
