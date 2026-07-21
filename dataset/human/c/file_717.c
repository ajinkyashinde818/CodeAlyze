#include <stdio.h>
#define mod 1000000007ll
typedef long long ll;


int main(void) {
  ll i, j, k, n, num[26], ans = 1;
  scanf("%lld", &n);
  char s[n + 10];
  scanf("%s", s);
  for(i = 0; i < 26; ++i) num[i] = 1;
  for(i = 0; i < n; ++i) num[s[i] - 'a']++;
  for(i = 0; i < 26; ++i) ans *= num[i], ans %= mod;
  ans = (ans - 1) % mod;
  printf("%lld", ans);
  return 0;
}
