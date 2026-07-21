#include <stdio.h>

long long gcd(long long  a, long long b)
{
    if (a < b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    
    return b ? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b)
{
    return a * b / gcd(a, b);
}

int main(void)
{
  long long a, b;
  scanf("%lld", &a);
  scanf("%lld", &b);
  //printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
  printf("%lld\n",lcm(a, b));
  return 0;
}
