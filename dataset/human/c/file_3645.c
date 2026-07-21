#include <stdio.h>

int gcd(int x, int y)
{
  if(y == 0) {
    return x;
  }
  else {
    return gcd(y, x%y);
  }
}

int main(void)
{
  long long int a, b;

  scanf("%lld %lld", &a, &b);

  printf("%lld\n", a*b/gcd(a,b));

  return 0;
}
