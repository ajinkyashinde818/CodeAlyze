#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N;

    scanf("%d", &N);

    int i;
    
    int *A = (int *) malloc(sizeof(int) * N);

    for(i = 0; i < N; i ++){
        scanf("%d", A + i);
    }
    int *B = (int *) malloc(sizeof(int) * N);
    
    for(i = 0; i < N; i ++){
        scanf("%d", B + i);
    }
    int *C = (int *) malloc(sizeof(int) * (N - 1));

    for(i = 0; i < N - 1; i ++){
        scanf("%d", C + i);
    }
    int current = A[0] - 1;
    int sum = B[current];
    int prev = current;

    for(i = 1; i < N; i ++){
        current = A[i] - 1;
        sum += B[current];

        if(current == prev + 1){
            sum += C[prev];
        }
        prev = current;
    }
    printf("%d\n", sum);
}
