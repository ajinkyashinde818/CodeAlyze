#include<stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d", &n);
    int *a = malloc(sizeof(int)*n+1);
    int *b = malloc(sizeof(int)*n+1);
    int *c = malloc(sizeof(int)*n);
    a[0]=-1; b[0]=0; c[0]=0;
    for(int i=1; i<=n; i++)
        scanf("%d", &a[i]);
    for(int i=1; i<=n; i++)
        scanf("%d", &b[i]);
    for(int i=1; i<=n-1; i++)
        scanf("%d", &c[i]);
    int points = 0;
    for(int i =1; i<=n; i++)
    {
        points += b[a[i]];
        if((a[i]+1==a[i+1]) && i!=n)
            points+=c[a[i]];
    }
    printf("%d\n", points);
    free(a); free(b); free(c);
    return 0;
}
