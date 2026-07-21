#include <stdio.h>
int N, L, ret, x[5000], a[5000], dp[5001][5001];
int main() {
	scanf("%d%d", &N, &L);
	for (int i = 0; i < N; i++) scanf("%d", &x[i]);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]), a[i] = a[i] ? a[i] : L;
	dp[N][L] = 1;
	for (int i = N - 1; i >= 0; i--) {
		int sum = dp[i + 1][L];
		for (int j = L - 1; j >= 0; j--) {
			if (j >= x[i] && (j - x[i]) % a[i] == 0) {
				dp[i][j] = sum;
			}
			sum = (sum + dp[i + 1][j]) % 1000000007;
		}
	}
	for (int i = 0; i < L; i++) ret = (ret + dp[0][i]) % 1000000007;
	printf("%d\n", ret);
	return 0;
}
