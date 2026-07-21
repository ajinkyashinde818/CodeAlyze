#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    long N;
    scanf("%ld",&N);
    long a[N-1],sum[N-1],usum[N-2];
    int i,j,k,l;
    for(i=0;i<N;i++)
    {
        scanf("%ld",&a[i]);
    }
    sum[0]=a[0];
    for(k=1;k<N;k++)
    {
        sum[k] =sum[k-1]+a[k];
    }
    for(l=0;l<N-1;l++)
    {
        usum[l]=sum[N-1]-(sum[l]*2);
        usum[l]=labs(usum[l]);
    }
    long min=usum[0];
    for(j=1;j<N-1;j++)
    {
        if(usum[j]<min)
        {
            min=usum[j];
        }
    }
    printf("%ld",min);
}
