#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ll long long

int main(void)
{
    int a,i;
    for(i=1;;i++)
    {
        scanf("%d",&a);
        if(a==0)
        break;
        printf("Case %d: %d\n",i,a);
    }
    return 0;
}
