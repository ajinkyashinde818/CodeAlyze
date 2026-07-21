//============================================================================
// 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//============================================================================
long maxval(long x, long y)
{
    if (x<y)
        return y;
    return x;
}
long minval(long x, long y)
{
    if (x<y)
        return x;
    return y;
}
//============================================================================
#define MAXVAL 2000000000
int main(void)
{
    long i,j,k, max, min, N, *Array;

    scanf("%ld", &N);
    Array = malloc(N*sizeof(long));
	for (i=0; i<N; i++)
        scanf("%ld", &Array[i]);
    //for (i=k=0, max=-MAXVAL, min=MAXVAL; i<N-1; i++)
    //if (Array[i]<min){
    //    min=Array[i];
    //    k=i;
    //}
    //max=-MAXVAL;
    for (j=1, max=-MAXVAL, min=*Array; j<N; j++){
        max=maxval(Array[j]-min, max);
        min=minval(Array[j], min);
        //printf("max=%ld, min=%ld\n", max, min);
    }
    free(Array);
    printf("%ld\n", max);
    return 0;
}
//============================================================================
