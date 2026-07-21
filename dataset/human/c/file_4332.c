#include <stdio.h>
#include <string.h>
#include <math.h>


int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	int ans = 1;
	int a, oldA = 0;
	long long dp[100002] = { 0 };
	long long mod = 1000000007;
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 0; i < m; ++i) {
		scanf("%d", &a);
		if (oldA && a - oldA == 1) {
			ans = 0;
		}
		oldA = a;
		dp[a + 1] = -1;
	}


	if (ans) {
		for (int i = 2; i < n + 2; ++i) {
			if (dp[i] == -1) {
				dp[i] = 0;
				continue;
			}
			dp[i] += dp[i - 1] != -1 ? dp[i - 1] : 0;
			dp[i] += dp[i - 2] != -1 ? dp[i - 2] : 0;
			dp[i] %= mod;

		}
		printf("%lld", dp[n + 1]);
	}
	else
	{
		printf("0");
	}




	return 0;
}
