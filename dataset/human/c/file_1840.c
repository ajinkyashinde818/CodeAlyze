#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d\n", &N);

    int *A = malloc(sizeof(int) * N);
    int *B = malloc(sizeof(int) * N);
    int *C = malloc(sizeof(int) * (N-1));

    for(int ni=0; ni<N; ni++){
        scanf("%d", A+ni);
    }
    for(int ni=0; ni<N; ni++){
        scanf("%d", B+ni);
    }
    for(int ni=0; ni<N-1; ni++){
        scanf("%d", C+ni);
    }

    int res = B[A[0]-1];
    for(int ni=1; ni<N; ni++){
        if(A[ni-1] == A[ni]-1){
            res += B[A[ni]-1] + C[A[ni-1]-1];
        } else {
            res += B[A[ni]-1];
        }
    }
    printf("%d\n", res);

    return 0;
}
