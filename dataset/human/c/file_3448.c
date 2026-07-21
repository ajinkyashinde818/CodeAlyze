#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, j, k, n, now = 0;
  scanf("%lld%lld", &n, &k);
  ll f[n], a[n];
  for(i = 0; i < n; ++i) scanf("%lld", &a[i]), a[i]--, f[i] = -1;
  f[0] = 0;
  while( 1 ) {
    if(f[a[now]] != -1) break;
    f[a[now]] = f[now] + 1;
    now = a[now];
  }
  if(f[a[now]] > k) {
    now = 0;
    for(i = 0; i < k; ++i) now = a[now];
  } else {
    k -= f[a[now]];
    k %= f[now] - f[a[now]] + 1;
    now = a[now];
    for(i = 0; i < k; ++i) now = a[now];
  }
  printf("%lld", now + 1);
  return 0;
}
