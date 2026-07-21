#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    int n,k,h,i=0,sum=0;
    float a;
    scanf("%d %d",&n,&k);
    while(i<n)
    {
        scanf("%d",&h);
        if(h>=k) sum++;
        i++;
    }
    printf("%d",sum);
    return 0;
}
