#include <stdio.h>
typedef long long ll;

ll gcd(ll a, ll b) {
  ll t;
  while(b) t = a % b, a = b, b = t;
  return a;
}

int main(void) {
  ll i, j, k, a, b, c, d, t, m;
  scanf("%lld", &t);
  for(i = 0; i < t; ++i) {
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    if(b > d || a < b) {
      printf("No\n");
      continue;
    }
    if(b <= c) {
      printf("Yes\n");
      continue;
    }
    a %= b;
    if(a > c) {
      printf("No\n");
      continue;
    }
    if(!(d % b)) {
      printf("Yes\n");
      continue;
    }
    m = gcd(d % b, b);
    if(a + (c - a) / m * m + m < b) printf("No\n");
    else printf("Yes\n");
  }
  return 0;
}
