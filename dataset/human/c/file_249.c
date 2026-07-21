#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>

int64_t max(int64_t a, int64_t b)
{
  return a > b ? a : b;
}

int main(void)
{
  int n;
  scanf("%d", &n);
  int64_t a[n];
  for (int i = 0; i < n; i++) {
    scanf("%" SCNd64, &a[i]);
  }
  int64_t dp[n + 1][2];
  dp[0][0] = 0;
  dp[0][1] = -1000000000000000;
  for (int i = 0; i < n; i++) {
    dp[i + 1][0] = max(dp[i][0] + a[i], dp[i][1] - a[i]);
    dp[i + 1][1] = max(dp[i][0] - a[i], dp[i][1] + a[i]);
  }
  printf("%" PRId64 "\n", dp[n][0]);
}
