#include<stdio.h>
int main()
{
    int tall[100000],i,count=0,K,N;
    scanf("%d %d",&N,&K);
    for(i=0;i<N;i++)
    {
        scanf("%d",&tall[i]);
    }
    for(i=0;i<N;i++)
    {
        if(tall[i]>=K)
        {
            count++;
        }
    }
    printf("%d",count);
    return 0;
}
