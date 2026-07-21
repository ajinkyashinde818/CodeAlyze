#include <stdio.h>
#define mod 1000000007
typedef long long ll;

int main(void) {
  ll i, j = 0, n, m, a;
  scanf("%lld%lld", &n, &m);
  ll dp[n + 5];
  for(i = 0; i < n; ++i) dp[i + 1] = 0;
  dp[0] = 1;
  for(i = 0; i < m; ++i) {
    scanf("%lld", &a);
    for(; j < a; ++j) 
      dp[j + 1] += dp[j], dp[j + 2] += dp[j], dp[j + 1] %= mod, dp[j + 2] %= mod;
    j = a + 1;
  }
  for(; j < n; ++j) 
    dp[j + 1] += dp[j], dp[j + 2] += dp[j], dp[j + 1] %= mod, dp[j + 2] %= mod;
  printf("%lld", dp[n]);
  return 0;
}
