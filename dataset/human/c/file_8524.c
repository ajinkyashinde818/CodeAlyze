#include <stdio.h>
typedef long long ll;

ll mabs(ll a) {
  return a > 0 ? a : -a;
}

int main(void) {
  ll i, n, max = 0, mn, a, m;
  scanf("%lld", &n);
  for(i = 0; i < n; ++i) {
    scanf("%lld", &a);
    if(mabs(a) > max) max = mabs(a), mn = i, m = a;
  }
  printf("%lld\n", 2 * n - 2);
  for(i = 0; i < n; ++i) if(i != mn) printf("%lld %lld\n", mn + 1, i + 1);
  if(m > 0) for(i = 1; i < n; ++i) printf("%lld %lld\n", i, i + 1);
  else for(i = 1; i < n; ++i) printf("%lld %lld\n", n - i + 1, n - i);
  return 0;
}
