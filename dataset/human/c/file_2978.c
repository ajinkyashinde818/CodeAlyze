#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, n, sum = 0, cnt = 0, be;
  scanf("%lld", &n);
  ll a[n];
  for(i = 0; i < n; ++i) scanf("%lld", &a[i]), sum += a[i];
  be = a[0];
  if(sum % (n * (n + 1) / 2)) {
    printf("NO");
    return 0;
  }
  sum /= n * (n + 1) / 2;
  for(i = 1; i < n; ++i) {
    be += sum;
    if(be - a[i] < 0 || (be - a[i]) % n) {
      printf("NO");
      return 0;
    }
    cnt += (be - a[i]) / n;
    be = a[i];
  }
  be += sum;
  if(be - a[0] < 0 || (be - a[0]) % n) {
    printf("NO");
    return 0;
  }
  cnt += (be - a[0]) / n;
  printf("YES");
  return 0;
}
