#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{
    int n,m,i,j;
    int a[200000],b[200000];
    bool bucket[200000] = {0};
    

    scanf("%d %d",&n,&m);

    for (i = 0; i < m; i++)
    {
        scanf("%d %d",&a[i],&b[i]);
        if(a[i] == 1)bucket[b[i] - 1] = 1;
    }
    for (i = 0; i < m; i++)
    {
        if(b[i] == n && bucket[a[i] - 1] == 1)break;
    }

    if(i == m)printf("IMPOSSIBLE");
    else printf("POSSIBLE");

}
