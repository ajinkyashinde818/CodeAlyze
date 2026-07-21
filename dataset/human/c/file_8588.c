#include <stdio.h>
typedef long long ll;

int main(void) {
  ll n, i, now = 1, cnt = 0;
  scanf("%lld", &n);
  bool flg[n + 1];
  ll a[n + 1];
  for(i = 0; i <= n; ++i) flg[i] = false;
  flg[1] = true;
  for(i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }
  while( 1 ) {
    if(now == 2) break;
    else if(flg[a[now]]) {
      printf("-1");
      return 0;
    } else {
      cnt++, now = a[now], flg[now] = true;
    }
  }
  printf("%lld", cnt);
  return 0;
}
