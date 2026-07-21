#include <stdio.h>

int abs(int a) {
  return a > 0 ? a : -a;
}

int max(int a, int b) {
  return a > b ? a : b;
}

int main(void) {
  int i, j, k, w, h, n, ans = 0, nowa, nowb;
  scanf("%d%d%d", &w, &h, &n);
  for(i = 0; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    if(i) {
      if((nowa - a) * (nowb - b) > 0) ans += max(abs(nowa - a), abs(nowb - b));
      else ans += abs(nowa - a) + abs(nowb - b);
    }
    nowa = a, nowb = b;
  }
  printf("%d\n", ans);
  return 0;
}
