#include <stdio.h>
#define mod 1000000007
typedef long long ll;

ll rev(ll a) {
  ll t = mod - 2, ans = 1;
  while(t) {
    if(t & 1) ans *= a, ans %= mod;
    a *= a, a %= mod, t >>= 1;
  }
  return ans;
}

int main(void) {
  ll i, j, x, y, sum, ans;
  scanf("%lld%lld", &x, &y);
  if((x + y) % 3) {
    printf("0");
    return 0;
  }
  sum = (x + y) / 3;
  if(x < sum || x > 2 * sum) {
    printf("0");
    return 0;
  }
  x -= sum;
  ll fact[sum + 1];
  fact[0] = 1;
  for(i = 1; i <= sum; ++i) fact[i] = (fact[i - 1] * i) % mod;
  ans = (fact[sum] * rev(fact[x])) % mod;
  ans *= rev(fact[sum - x]), ans %= mod;
  printf("%lld", ans);
  return 0;
}
