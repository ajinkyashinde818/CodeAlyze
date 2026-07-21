#include <stdio.h>
int main()
{
    int n,D,X,i;
    scanf("%d%d%d",&n,&D,&X);
    int sz[n];
    for(i=0; i<n; i++)
        scanf("%d",&sz[i]);

    for(i=0;i<n;i++)
    {
        X=X+(D-1)/sz[i]+1;
    }
    printf("%d",X);
}
