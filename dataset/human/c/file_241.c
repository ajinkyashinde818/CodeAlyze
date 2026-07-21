#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;
typedef int64_t i64;

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) > (0) ? (a) : -(a))

void run (void) {
  i32 n;
  scanf ("%" SCNi32, &n);
  i64 sum = 0;
  i32 min = 1000000000;
  i32 neg = 0;
  for (i32 i = 0; i < n; ++i) {
    i32 a;
    scanf ("%" SCNi32, &a);
    if (a < 0) {
      neg++;
    }
    i32 v = ABS(a);
    sum += v;
    min = MIN(min, v);
  }
  if (neg % 2 == 1) {
    sum -= 2 * min;
  }
  printf ("%" PRIi64 "\n", sum);
}

int main (void) {
  run();
  return 0;
}
