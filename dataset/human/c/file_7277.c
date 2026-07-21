#include <stdio.h>
#include <stdlib.h>
 
#define MAX 6400
 
int main()
{
	int i, j, H, W, A[82][82], B[82][82], D[82][82];
	scanf("%d %d", &H, &W);
	for (i = 1; i <= H; i++) {
		for (j = 1; j <= W; j++) scanf("%d", &(A[i][j]));
	}
	for (i = 1; i <= H; i++) {
		for (j = 1; j <= W; j++) {
			scanf("%d", &(B[i][j]));
			D[i][j] = abs(A[i][j] - B[i][j]);
		}
	}
	
	int k, dp[2][82][MAX + 1] = {};
	for (j = 2, dp[1][1][D[1][1]] = 1; j <= W; j++) {
		for (k = 0; k <= MAX; k++) {
			if (dp[1][j-1][k] == 1) {
				dp[1][j][abs(k - D[1][j])] = 1;
				if (k + D[1][j] <= MAX) dp[1][j][k + D[1][j]] = 1;
			}
		}
	}
	for (i = 2; i <= H; i++) {
		for (j = 1; j <= W; j++) {
			for (k = 0; k <= MAX; k++) dp[i%2][j][k] = 0;
		}
		for (k = 0; k <= MAX; k++) {
			if (dp[1-i%2][1][k] == 1) {
				dp[i%2][1][abs(k - D[i][1])] = 1;
				if (k + D[i][1] <= MAX) dp[i%2][1][k + D[i][1]] = 1;
			}
		}
		for (j = 2; j <= W; j++) {
			for (k = 0; k <= MAX; k++) {
				if (dp[i%2][j-1][k] == 1) {
					dp[i%2][j][abs(k - D[i][j])] = 1;
					if (k + D[i][j] <= MAX) dp[i%2][j][k + D[i][j]] = 1;
				}
				if (dp[1-i%2][j][k] == 1) {
					dp[i%2][j][abs(k - D[i][j])] = 1;
					if (k + D[i][j] <= MAX) dp[i%2][j][k + D[i][j]] = 1;
				}
			}
		}
	}
	
	for (k = 0; k <= MAX; k++) if (dp[H%2][W][k] == 1) break;
	printf("%d\n", k);
	fflush(stdout);
	return 0;
}
