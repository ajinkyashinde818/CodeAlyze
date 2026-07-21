#include <stdio.h>
#include <stdlib.h>
long gcd(long x,long y)
{
    if(x<y)
    {
        x+=y;
        y=x-y;
        x-=y;
    }
    long a,b,c;
    a=y,b=x%y;
    while(b!=0)
    {
        c=a;
        a=b;
        b=c%a;
    }
    return a;
}
int main()
{
    long a,b;
    scanf("%ld %ld",&a,&b);
    printf("%ld\n",a*b/gcd(a,b));
    return 0;
}
