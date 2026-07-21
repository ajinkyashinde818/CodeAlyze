#include <stdio.h>

int main()
{
    int n,a[20],b[20],c[20],i,j,ans = 0;

    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d",&b[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        scanf("%d",&c[i]);
    }   

    ans += b[a[0] - 1];
    for (i = 1; i < n; i++)
    {
        ans += b[a[i] - 1];
        if (a[i] == a[i - 1] + 1)
        {
            ans += c[a[i] - 2];            
        }
    }
    
    printf("%d",ans);
}
