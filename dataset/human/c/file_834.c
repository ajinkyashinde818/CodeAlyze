#include <stdio.h>

int main()
{
	int i, N, a[51], b[51];
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &(a[i]));
	for (i = 1; i <= N; i++) scanf("%d", &(b[i]));
	for (i = 1; i <= N; i++) if (b[i] != a[i]) break;
	if (i > N) {
		printf("0\n");
		fflush(stdout);
		return 0;
	}
	for (i = 1; i <= N; i++) if (b[i] != a[i] && b[i] * 2 >= a[i]) break;
	if (i <= N) {
		printf("-1\n");
		fflush(stdout);
		return 0;
	}
	
	int j, k, l, adj[51][51] = {};
	long long bit[51], ans;
	for (i = 1, bit[0] = 1; i <= 50; i++) bit[i] = bit[i-1] << 1;
	for (i = 49, ans = bit[50] - 2; i >= 1; i--) {
		ans ^= bit[i];
		for (j = 0; j <= 50; j++) for (k = 0, adj[j][j] = 1; k < j; k++) adj[j][k] = 0;
		for (j = 1; j < 50; j++) {
			if ((ans & bit[j]) == 0) continue;
			for (k = j; k <= 50; k++) adj[k][k%j] = 1;
		}
		for (l = 1; l <= 50; l++) {
			for (j = l; j <= 50; j++) {
				for (k = 0; k <= l; k++) if ((adj[j][l] & adj[l][k]) == 1) adj[j][k] = 1;
			}
		}
		for (j = 1; j <= N; j++) if (adj[a[j]][b[j]] == 0) break;
		if (j <= N) ans ^= bit[i];
	}
	
	printf("%lld\n", ans);
	fflush(stdout);
	return 0;
}
