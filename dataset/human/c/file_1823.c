#include <stdio.h>

int main(void){
    int counter = 0;
    int N;
    scanf("%i", &N);
    int A[N];
    for (int i = 0; i < N; i++){
        scanf("%i", &A[i]);
    }
    int B[N];
    for (int i = 0; i < N; i++){
        scanf("%i", &B[i]);
        counter += B[i];
    }
    int C[N - 1];
    for (int i = 0; i < N - 1; i++){
        scanf("%i", &C[i]);
    }
    for (int i = 0; i < N - 1; i++){
        if (A[i] + 1 == A[i + 1]){
            counter += C[A[i] - 1];
        }
    }
    printf("%i\n", counter);
}
