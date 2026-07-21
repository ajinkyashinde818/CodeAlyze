#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n,a[100000],i,j,now = 1;

    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    
    for (i = 0; i < n; i++)
    {
        now = a[now - 1];
        if(now == 2)break;
    }
    printf("%d",i == n ? -1 : i + 1);
}
