#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;

void trans (i32 a, i32 *dp, i32 n) {
  for (i32 i = a; i <= n; ++i) {
    dp[i] += dp[i - a];
  }
}

void run (void) {
  i32 a, b, c, n;
  scanf ("%" SCNi32 "%" SCNi32 "%" SCNi32 "%" SCNi32, &a, &b, &c, &n);
  i32 *dp = (i32 *) calloc (n + 1, sizeof (i32));
  dp[0] = 1;
  trans (a, dp, n);
  trans (b, dp, n);
  trans (c, dp, n);
  printf ("%" PRIi32 "\n", dp[n]);
}

int main (void) {
  run();
  return 0;
}
