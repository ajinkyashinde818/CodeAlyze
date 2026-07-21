#include <stdio.h>
#include <stdlib.h>

int GCD(long long a,long long b)
{
    int c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}


int main()
{   long long a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld",a*b/GCD(a,b));

    return 0;
}
