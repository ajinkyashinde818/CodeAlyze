#include<stdio.h>
int main()
{
    int N,K,h[100000],n,i;
    scanf("%d%d",&N,&K);
    for(i=0,n=0;i<N;i++)
    {
    scanf("%d",&h[i]);
    if(h[i]>=K)
    {
        n=n+1;
    }
    }
    printf("%d\n",n);
    return 0;
}
