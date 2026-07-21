#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if((a+b)==c)
        printf("%d",c+b);
    else if(a+b<c)
        printf("%d",(a+b)+b+1);
    else if(a+b>c)
            printf("%d",b+c); 
    return 0;
}
