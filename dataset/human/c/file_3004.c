#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, k, n, a, ans = 0, s, b;
  scanf("%lld%lld", &k, &n);
  scanf("%lld", &s), b = s;
  for(i = 1; i < n; ++i) {
    scanf("%lld", &a);
    if(ans < a - b) ans = a - b;
    b = a;
  }
  if(ans < s + k - a) ans = s + k - a;
  printf("%lld", k - ans);
  return 0;
}
