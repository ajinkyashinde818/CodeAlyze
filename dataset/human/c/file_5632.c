#include <stdio.h>
typedef long long ll;

int
main(int argc, char *argv[])
{
  ll x;
  scanf("%lld", &x);
  ll y = x - (x / 11) * 11;
  ll ans = 2 * (x / 11);
  if(0 < y && y <= 6) ++ans;
  else if(6 < y) ans += 2;
  printf("%lld\n", ans);

  return 0;
}
