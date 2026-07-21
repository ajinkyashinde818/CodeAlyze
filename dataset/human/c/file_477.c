#include <stdio.h>
typedef long long ll;

ll abs(ll a) {
  return a > 0 ? a : -a;
}

int main(void) {
  ll i, j, k, n, ans = 10e15;
  scanf("%lld", &n);
  ll sum[n];
  for(i = 0; i < n; ++i) {
    scanf("%lld", &sum[i]);
    if(i) sum[i] += sum[i - 1];
  }
  for(i = 0; i < n - 1; ++i) {
    if(abs(2 * sum[i] - sum[n - 1]) < ans) ans = abs(2 * sum[i] - sum[n - 1]);
  }
  printf("%lld", ans);
  return 0;
}
