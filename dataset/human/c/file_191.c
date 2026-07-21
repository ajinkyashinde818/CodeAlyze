#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, j, n, ans = 0, min = 1e9, a;
  bool now = false;
  scanf("%lld", &n);
  for(i = 0; i < n; ++i) {
    scanf("%lld", &a);
    if(a < 0) now = !now;
    a = a > 0 ? a : -a;
    ans += a;
    if(min > a) min = a;
  }
  if(now) ans -= min * 2;
  printf("%lld", ans);
  return 0;
}
