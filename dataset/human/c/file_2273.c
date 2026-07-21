#include <stdio.h>
#define MAX_N 1000

int main(void) {
  int n, i, j, k, ans, temp;
  int dp[MAX_N][MAX_N];
  char a[MAX_N][MAX_N];

  while (1) {
    scanf("%d", &n);
    if (n == 0) return 0;

    for (i = 0; i < n; i++) {
      scanf("%s", a[i]);
    }

    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
	if (a[i][j] == '.') dp[i][j] = 1;
	else dp[i][j] = 0;
      }
    }

    for (i = 1; i < n; i++) {
      for (j = 1; j < n; j++) {
	if (dp[i][j] == 0) continue;
	int temp = dp[i - 1][j - 1];
	if (temp > dp[i][j - 1]) temp = dp[i][j - 1];
	if (temp > dp[i - 1][j]) temp = dp[i - 1][j];
	
	dp[i][j] = temp + 1;
      }
    }

    int ans = 0;
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
	if (dp[i][j] > ans) ans = dp[i][j];
      }
    }

    printf("%d\n", ans);
  }
}
