#include <stdio.h>

#define MOD_VAL	1000000007

long long int modpow(long long int a, long long int n, long long int mod) {
  long long int res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

long long int modinv(long long int a) {
  return modpow(a, (long long int)(MOD_VAL - 2), (long long int)MOD_VAL);
}

long long int factorial_mod(long long int a)
{
  long long int ret = 1;
  while( a > 1 ) {
    ret = (ret * a) % (long long int)MOD_VAL;
    a--;
  }
  return ret;
}

long long int combination_mod(long long int n, long long int k)
{
  long long int bunbo, bunshi;
  bunshi = factorial_mod( n );
  bunbo = (factorial_mod( k ) * factorial_mod( n-k )) % (long long int)MOD_VAL;
  return (bunshi * modinv( bunbo )) % (long long int)MOD_VAL;
}

int main()
{
  int ret, X, Y;
  int n, m;
  ret = scanf("%d %d", &X, &Y);
  if ( (X + Y) % 3 != 0 ) {
    printf("0\n");
    return 0;
  }
  n = (2 * X - Y) / 3;
  m = (2 * Y - X) / 3;
  if ( n < 0 || m < 0 ) {
    printf("0\n");
    return 0;
  }
  printf("%lld\n", combination_mod( (long long int)(n + m), (long long int)n ));
}
