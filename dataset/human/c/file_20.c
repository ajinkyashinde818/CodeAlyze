#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, j, r, g, b, n, ans = 0;
  scanf("%lld%lld%lld%lld", &r, &g, &b, &n);
  for(i = 0; i * r <= n; ++i) for(j = 0; i * r + j * g<= n; ++j) if(!((n - i * r - j * g) % b)) ++ans;
  printf("%lld", ans);
  return 0;
}
