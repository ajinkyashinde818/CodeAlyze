#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, j, n, ans;
  scanf("%lld", &n);
  ll a[n], b[n], c[n];
  for(i = 0; i < n; ++i) scanf("%lld", &a[i]), a[i]--;
  for(i = 0; i < n; ++i) scanf("%lld", &b[i]);
  for(i = 1; i < n; ++i) scanf("%lld", &c[i]);
  ans = b[a[0]];
  for(i = 1; i < n; ++i) {
    ans += b[a[i]];
    if(a[i] == a[i - 1] + 1) ans += c[a[i]];
  }
  printf("%lld", ans);
  return 0;
}
