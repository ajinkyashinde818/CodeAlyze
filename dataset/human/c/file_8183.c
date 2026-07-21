#include <stdio.h>

int main(void)
{
    int a1,a2,b1,b2,a,b;
    scanf("%d %d %d %d",&a1,&a2,&b1,&b2);
    a=a1*a2;b=b1*b2;
    if(a>=b) printf("%d",a);
    else if(a<b) printf("%d",b);
    return 0;
}
