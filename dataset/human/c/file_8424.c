#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;
typedef int64_t i64;

void run (void) {
  i32 n, k;
  scanf ("%" SCNi32 "%" SCNi32, &n, &k);
  i32 *a = (i32 *) calloc (n, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    scanf ("%" SCNi32, a + i);
  }
  i64 *sum = (i64 *) calloc (n + 1, sizeof (i64));
  for (i32 i = 1; i <= n; ++i) {
    sum[i] = sum[i - 1] + a[i - 1];
  }
  i64 ans = 0;
  for (i32 bit = 40; bit >= 0;bit--) {
    i32 cnt = 0;
    for (i32 l = 0; l < n; ++l) {
      for (i32 r = l + 1; r <= n; ++r) {
	i64 v = sum[r] - sum[l];
	if ((v & ans) != ans) continue;
	cnt += (v >> bit) & 1;
      }
    }
    if (cnt >= k) {
      ans += (i64) 1 << bit;
    }
  }
  printf ("%" PRIi64 "\n", ans);
}

int main (void) {
  run ();
  return 0;
}
