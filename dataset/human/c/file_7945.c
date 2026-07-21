#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, j, k, n, c;
  scanf("%lld%lld%lld", &n, &k, &c);
  char s[n + 10];
  scanf("%s", s);
  ll cnt[2][n], las = -1e9;
  cnt[0][0] = cnt[1][n - 1] = 0;
  for(i = 1; i < n; ++i) {
    cnt[0][i] = cnt[0][i - 1];
    if(s[i - 1] == 'o' && i - 1 > las + c) cnt[0][i]++, las = i - 1;
  }
  las = 1e9;
  for(i = n - 2; i >= 0; --i) {
    cnt[1][i] = cnt[1][i + 1];
    if(s[i + 1] == 'o' && i + 1 < las - c) cnt[1][i]++, las = i + 1;
  }
  for(i = 0; i < n; ++i) if(cnt[0][i] + cnt[1][i] < k) printf("%lld\n", i + 1);
  return 0;
}
