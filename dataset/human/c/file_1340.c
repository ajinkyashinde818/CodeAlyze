#include <stdio.h>
#include <string.h>

int main (void)
{
    int n,m,i;
    scanf("%d %d",&n,&m);
    int a[m+1][2],b[n+1];
    for(i=1;i<=n;i++)
    {
        b[i]=0;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a[i][0],&a[i][1]);
        if(a[i][0]==1)
        {
            b[a[i][1]]++;
        }
    }
    for(i=1;i<=m;i++)
    {
        if(a[i][1]==n&&b[a[i][0]]!=0)
        {
            puts("POSSIBLE");
            return 0;
        }
    }
    puts("IMPOSSIBLE");
    return 0;
}
