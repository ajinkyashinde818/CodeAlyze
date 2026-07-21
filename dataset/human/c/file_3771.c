#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    long a,b,c,i,gcd;

    scanf("%ld %ld",&a,&b);

    c=(a<b)? a:b;

    for ( i = 1; i <= c; i++)
    {
        if(a%i==0&&b%i==0) gcd=i;
    }

    printf("%ld",(a*b)/gcd);

    return 0;
}
