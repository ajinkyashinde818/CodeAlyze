#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d,area1,area2;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    area1=a*b;
    area2=c*d;
    if(area1>=area2) printf("%d",area1);
    else printf("%d",area2);
    return 0;
}
