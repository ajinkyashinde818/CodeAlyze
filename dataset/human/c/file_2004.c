#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  long a, b, c, ans = 0;

  if(scanf("%ld %ld %ld", &a, &b, &c) == 1);

  if(b >= c) {
    ans = c * 2;
    b = b - c;
    if(b > 0) {
      ans += b;
    }
  } else {
    ans = b * 2;
    c = c - b;
    while(c > 0 && a >= 0) {
      c--;
      a--;
      ans++;
    }
  }

  printf("%ld", ans);

  return 0;
}
