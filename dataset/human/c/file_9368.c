#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,day,l,a,i;
    scanf("%d",&n);
    scanf("%d%d",&day,&l);
    m=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        m+=(day-1)/a+1;
    }
    printf("%d",l+m);
    return 0;
}
