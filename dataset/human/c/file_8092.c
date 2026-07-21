#include <stdio.h>
#include <math.h>
#include <string.h>
int max(int a,int b)
{
    if (a>b) {
        return a;
    }
    else return b;
}
int main()
{
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    printf("%d",max(a*b, c*d));
    return 0;
}
