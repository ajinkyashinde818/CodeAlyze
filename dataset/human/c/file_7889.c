#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, j, k = 100000, n, m, a, cnt[k], now, ans = 1, max = 0;
  bool p[k];
  scanf("%lld%lld", &n, &m);
  for(i = 0; i < k; ++i) p[i] = true, cnt[i] = 0;;
  for(i = 2; i * i < k; ++i) if(p[i]) for(j = 2; i * j < k; ++j) p[i * j] = false;
  for(i = 0; i < n; ++i) {
    scanf("%lld", &a);
    a /= 2;
    for(j = 2; j * j <= a; ++j) if(p[j]) {
      now = 0;
      while(!(a % j)) now++, a /= j;
      if(j == 2) {
        if(!i) cnt[2] = now;
        else if(cnt[2] != now) {
          printf("0");
          return 0;
        }
      } else if(cnt[j] < now) cnt[j] = now;
      if(a == max) break;
    }
    if(a < k) {
      if(!cnt[a]) cnt[a]++;
    } else {
      if(a != max) ans *= a;
      max = a;
      if(ans > m) {
        printf("0");
        return 0;
      }
    }
  }
  for(i = 2; i < k; ++i) {
    a = 1;
    for(j = 0; j < cnt[i]; ++j) a *= i;
    ans *= a;
    if(ans > m) {
      printf("0");
      return 0;
    }
  }
  printf("%lld", (m / ans + 1) / 2);
  return 0;
}
