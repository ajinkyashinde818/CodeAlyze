#include <stdio.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define repi(i, n, a) for(int i = a; i < n; ++i)

int main(void) {
  int n, i, j, max = 0, now = 0;
  scanf("%d", &n);
  int r[n], d[n];
  d[0] = 0;
  rep(i, n) {
    scanf("%d", &r[i]);
    if(i) d[i] = r[i] - r[i - 1];
  }
  rep(i, n) {
    now += d[i];
    if(now < 0) now = 0;
    if(now > max) max = now;
  }
  if(!max) {
    max = -10e9 - 7;
    repi(i, n, 1) {
      if(max < d[i]) max = d[i];
    }
  }
  printf("%d\n", max);
  return 0;
}
