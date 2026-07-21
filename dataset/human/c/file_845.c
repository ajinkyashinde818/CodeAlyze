#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, j, n, m = 1e6, ans = 0;
  bool p[m];
  for(i = 0; i < m; ++i) p[i] = true;
  for(i = 2; i < 1000; ++i) if(p[i]) {
    for(j = 2; i * j < m; ++j) p[i * j] = false;
  }
  for(i = 1000; i > 1; --i) if(p[i]) {
    for(j = i; j < m; j *= i) p[j] = true;
  }
  scanf("%lld", &n);
  for(i = 2; i < m; ++i) if(p[i] && !(n % i)) ans++, n /= i;
  if(n > m) ++ans;
  printf("%lld", ans);
  return 0;
}
