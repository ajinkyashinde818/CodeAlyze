#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s,h,a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
        s=a*b;
        h=c*d;
        if(s<=h)
            printf("%d\n",h);
        else
            printf("%d\n",s);
    return 0;
}
