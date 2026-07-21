#include <stdio.h>

int main(void)
{
    int N, A[20], B[20], C[20], i, n[2]={-1,-1}, sum=0;

    scanf("%d", &N);

    for(i=0; i<N; i++){
        scanf("%d", &A[i]);
    }

    for(i=0; i<N; i++){
        scanf("%d", &B[i]);
    }

    for(i=0; i<N-1; i++){
        scanf("%d", &C[i]);
    }

    for(i=0; i<N; i++){
        n[1] = A[i];

        sum += B[n[1]-1];

        if(n[1] == n[0] + 1){
            sum += C[n[0]-1];
        }

        n[0] = n[1];
    }

    printf("%d\n", sum);

    return 0;
}
