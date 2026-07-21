#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ll long long int

int gcd(ll x, ll y)
{
  return y ? gcd(y, x % y) : x;
}

int main(void)
{
  ll a, b;
  scanf("%lld %lld", &a, &b);

  ll an = (a * b) / gcd(a, b);
  printf("%lld\n", an);
  return 0;
}
