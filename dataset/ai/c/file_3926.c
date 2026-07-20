#include <stdio.h>
long long factorial(int n)
{
    return n < 2 ? 1 : n * factorial(n - 1);
}
int main(void)
{
    printf("%lld\n", factorial(9));
    return 0;
}
