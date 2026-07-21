#include <stdio.h>
int main()
{
    int a,b,x,i;
    long long int c;
    scanf("%d%d",&a,&b);
    if(a<=b)
        x=a;
    else
        x=b;
    for(i=x;i>=1;i--)
    {
        if(a%i==0&&b%i==0)
            break;
    }
    c=a*1.0*b/i;
    printf("%lld",c);
    return 0;
}
