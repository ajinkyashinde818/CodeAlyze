#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, k, n, h, ans = 0;
  scanf("%lld%lld", &n, &k);
  for(i = 0; i < n; ++i) {
    scanf("%lld", &h);
    if(h >= k) ++ans;
  }
  printf("%lld", ans);
  return 0;
}
