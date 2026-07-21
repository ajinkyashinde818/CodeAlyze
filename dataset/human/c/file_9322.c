#include <stdio.h>
#define D_SIZE_BUFF 200000

int main()
{
    long N,K;
    int h,count=0;

    scanf("%ld %ld",&N,&K);

    for( int i=0; i<N; i++)
    {
        scanf("%d",&h);
        if(K <= h) count++;
    }

    printf("%d",count);

    return 0;
}
