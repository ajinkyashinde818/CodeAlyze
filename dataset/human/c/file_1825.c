#include <stdio.h>
int main(void){
    // Your code here!
    int N, A[20], B[20], C[20];
    long sum = 0;
    scanf("%d",&N);
    
    for(int i = 0; i < N; i++)
        scanf("%d",&A[i]);
    for(int i = 0; i < N; i++)
        scanf("%d",&B[i]);
    for(int i = 0; i < N-1; i++)
        scanf("%d",&C[i]);
    
    sum += B[A[0]-1];
    for(int i = 1; i < N; i++)
    {
        if(A[i]-A[i-1] == 1)
            sum += B[A[i]-1] + C[A[i-1]-1];
        else
            sum += B[A[i]-1];
    }
        
    printf("%ld\n",sum);
}
