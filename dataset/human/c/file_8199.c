#include<stdio.h>
int main()
{
    int a,b,c,d,area1,area2;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    area1=a*b;
    area2=c*d;
    if(area1>=area2)
    {
        printf("%d\n",area1);
    }
    if(area2>area1)
    {
        printf("%d\n",area2);
    }

    return 0;

}
