#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;
typedef int64_t i64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))

void run (void) {
  i32 n;
  scanf ("%" SCNi32, &n);
  i32 *a = ALLOC (n * n, i32);
  for (i32 i = 0; i < n * n; ++i) {
    scanf ("%" SCNi32, a + i);
  }
  i64 *dp = ALLOC (1 << n, i64);
  for (i32 i = 1; i < (1 << n); ++i) {
    i64 sum = 0;
    for (i32 j = 0; j < n; ++j) {
      if (((i >> j) & 1) == 0) continue;
      for (i32 k = j + 1; k < n; ++k) {
        if (((i >> k) & 1) == 0) continue;
        sum += a[j * n + k];
      }
    }
    i64 max = MAX (0, sum);
    for (i32 j = (i - 1) & i; j > (i ^ j); j = (j - 1) & i) {
      i64 x = dp[j] + dp[i ^ j];
      max = MAX (max, x);
    }
    dp[i] = max;
  }
  printf ("%" PRIi64 "\n", dp[(1 << n) - 1]);
}

int main (void) {
  run();
  return 0;
}
