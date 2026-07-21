#include <stdio.h>
#define abs(x) ((x) > 0 ? (x) : -(x))
#define min(x, y) ((x) < (y) ? (x) : (y))

int
main(int argc, char *argv[])
{
  int n, a[200000];
  long long int sum = 0, sum2 = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
    sum += (long long)a[i];
  }
  long long ans = abs(2*(long long)a[0] - sum);
  for(int i = 0; i < n - 1; i++){
    sum2 += (long long)a[i];
    sum -= (long long)a[i];
    ans = min(ans, abs(sum - sum2));
  }
  printf("%lld\n", ans);
  return 0;
}
