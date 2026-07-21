#include<stdio.h>
int main(void)
{
    int k,n,a[200001],i,L[200001],g;
    scanf("%d %d",&k,&n);
    for(i = 1 ; i <= n ; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i = 1 ; i <= n-1 ; i++)
    {
        L[i] = a[i+1] - a[i];
    }
    L[n] = a[1] + k - a[n];
    g = L[1];
    for(i = 1 ; i <= n ; i++)
    {
        if(L[i] > g)
        {
            g = L[i];
        }
    }
    printf("%d\n",k - g);
    return 0;

}
