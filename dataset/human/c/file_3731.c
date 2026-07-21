#include <stdio.h>
#include <stdlib.h>
long long gcd(long long m,long long n)
{
    long long mod;
    while(n!=0)
    {
        mod=m%n;
        m=n;
        n=mod;
    }
    return m;
}
int main()
{
   long long A,B;
   scanf("%lld%lld",&A,&B);
   printf("%lld",A*B/gcd(A,B));
    return 0;
}
