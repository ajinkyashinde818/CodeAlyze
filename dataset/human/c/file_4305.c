#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;

#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))

void run (void) {
  i32 n, m;
  scanf ("%" SCNi32 "%" SCNi32, &n, &m);
  i32 *a = ALLOC (n, i32);
  for (i32 i = 0; i < m; ++i) {
    i32 b;
    scanf ("%" SCNi32, &b);
    a[b] = 1;
  }
  i32 *dp = ALLOC (n + 2, i32);
  const i32 mod = 1000000007;
  dp[0] = 1;
  for (i32 i = 0; i < n; ++i) {
    if (a[i]) {
      dp[i] = 0;
    } else {
      dp[i + 1] = (dp[i + 1] + dp[i]) % mod;
      dp[i + 2] = (dp[i + 2] + dp[i]) % mod;
    }
  }
  printf ("%" PRIi32 "\n", dp[n]);
}

int main (void) {
  run();
  return 0;
}
