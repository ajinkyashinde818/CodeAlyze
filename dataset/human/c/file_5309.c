#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, j, k, n, m, x, ans = 1e9, cnt;;
  scanf("%lld%lld%lld", &n, &m, &x);
  ll c[n], a[n][m], now[m];
  for(i = 0; i < n; ++i) {
    scanf("%lld", &c[i]);
    for(j = 0; j < m; ++j) scanf("%lld", &a[i][j]), a[i][j];
  }
  for(i = 0; i < (1 << n); ++i) {
    cnt = 0;
    for(j = 0; j < m; ++j) now[j] = 0;
    for(j = 0; j < n; ++j) if((i >> j) & 1) {
      for(k = 0; k < m; ++k) now[k] += a[j][k];
      cnt += c[j];
    }
    for(j = 0; j < m; ++j) if(now[j] < x) break;
    if(j == m && ans > cnt) ans = cnt;
  }
  printf("%lld", ans != 1e9 ? ans : -1);
  return 0;
}
