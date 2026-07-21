#include <stdio.h>
int main()
{
    long long int n1, n2, i, gcd,rem,c,d;
    scanf("%lld %lld",&n1,&n2);
    c=n1*n2;
    while(n2!=0)
    {
        rem=n1%n2;
        n1=n2;
        n2=rem;
    }
    gcd=n1;
    d=(c/gcd);
    printf("%lld\n",d);
    return 0;
}
