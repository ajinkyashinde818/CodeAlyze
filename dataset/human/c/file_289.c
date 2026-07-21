#include <stdio.h>
#include <stdlib.h>
typedef long long ll;

int main(void)
{
  int n, i;
  ll a[100000];
  int count;
  ll ans = 0;
  ll max = -1000000000;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    if (a[i] < 0)
      count++;
    if (llabs(max) > llabs(a[i]))
        max = a[i];
    ans += llabs(a[i]);
  }
  if (count % 2 == 0)
    printf("%lld\n", ans);
  else
    printf("%lld\n", ans-2*llabs(max));
}
