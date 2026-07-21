#include <stdio.h>
typedef long long ll;

ll gcd(ll a, ll b) {
  ll t;
  while(b) t = a % b, a = b, b = t;
  return a;
}

int main(void) {
  ll a, b;
  scanf("%lld%lld", &a, &b);
  printf("%lld", a * b / gcd(a, b));
  return 0;
}
