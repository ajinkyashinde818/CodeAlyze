#include <stdio.h>
int main(void)
{
    int A[20];
    int B[20];
    int C[19];
    int N;
    int i;
    int sum = 0;
    int index;
    
    scanf( "%d", &N );
    
    if( N<=20 )
    {
        for(i=0; i<N; i++)
        {
            scanf( "%d", &A[i]);
        }
        for(i=0; i<N; i++)
        {
            scanf( "%d", &B[i]);
        }
        for(i=0; i<N-1; i++)
        {
            scanf( "%d", &C[i]);
        }
    }
    
    
    for(i=0; i<N; i++)
    {
        index = A[i]-1;
        sum = sum + B[index];
        
        if( A[i] == (A[i+1]-1) )
        {
            sum = sum + C[index];
        }
    }
    
    printf( "%d",sum );
    return(0);
}
