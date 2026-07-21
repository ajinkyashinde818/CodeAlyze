#include <stdio.h>

int main (void)
{
    int a,b,c,d;

    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    scanf("%d",&d);

    if(a*b == c*d)
        printf("%d\n",a*b);
    else if(a*b > c*d)
        printf("%d\n",a*b);
    else
        printf("%d\n",c*d);


    return 0;
}
