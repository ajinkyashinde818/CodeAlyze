#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a[100000],minus_count = 0;
    int i,j;

    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        if(a[i] < 0)minus_count++;
    }
    
    long long ans = 0,min = 2000000000;
    for (i = 0; i < n; i++)
    {
        ans += abs(a[i]);
        if(min > abs(a[i]))min = abs(a[i]);
    }
    
    if(minus_count % 2 == 0)
    {
        printf("%lld",ans);
    }
    else
    {
        printf("%lld",ans - min * 2);
    }
    
}
