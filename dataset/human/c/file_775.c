#include <stdio.h>

int main(void) {
  int i, j, k, d, g, p, c;
  scanf("%d%d", &d, &g);
  g /= 100;
  int dp[d * 100 + 1];
  for(i = 0; i <= d * 100; ++i) dp[i] = 0;
  for(i = 1; i <= d; ++i) {
    int tmp[d * 100 + 1];
    for(j = 0; j <= d * 100; ++j) tmp[j] = dp[j];
    scanf("%d%d", &p, &c);
    c /= 100;
    for(j = 1; j < p; ++j) for(k = 0; k < d * 100; ++k) if(j + k <= d * 100 && tmp[j + k] < dp[k] + i * j) tmp[j + k] = dp[k] + i * j;
    for(j = 0; p + j <= d * 100; ++j) if(tmp[p + j] < dp[j] + p * i + c) tmp[p + j] = dp[j] + p * i + c;
    for(j = 0; j <= d * 100; ++j) dp[j] = tmp[j];
  }
  for(i = 0; i <= d * 100; ++i) if(dp[i] >= g) {
    printf("%d", i);
    break;
  }
  return 0;
}
