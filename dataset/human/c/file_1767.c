#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    int N;
    scanf("%d", &N);
    int *A = (int*)malloc((N) * sizeof(int));
    int *B = (int*)malloc((N) * sizeof(int));
    int *C = (int*)malloc((N-1) * sizeof(int));
    int i;
    int temp;
    for(i=0; i<N; i++) {
        scanf("%d", &A[i]);
    }
    for(i=0; i<N; i++) {
        scanf("%d", &B[i]);
    }
    for(i=0; i<N-1; i++) {
        scanf("%d", &C[i]);
    }
    int sum = 0;
    for(i=0; i<N; i++) {
        sum += B[A[i]-1];
        // printf("%d, %d\n", A[i], B[A[i]-1]);
        if(A[i] == A[i-1] + 1) {
            sum += C[A[i-1]-1];
            // printf("%d\n", C[A[i-1]-1]);
        }
    }
    printf("%d\n", sum);

    return 0;
}
