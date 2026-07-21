#include <stdio.h>
typedef long long ll;
#define abs(x) ((x) > 0 ? (x) : -(x))

int
main(int argc, char *argv[])
{
  int n;
  ll a[100000], sum = 0, min = 1000000000; int minus = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%lld", &a[i]);
    sum += abs(a[i]);
    if(a[i] < 0) minus++;
    min = (min > abs(a[i]) ? abs(a[i]) : min);
  }

  printf("%lld\n", sum - (minus % 2) * 2 * min);

  return 0;
}
