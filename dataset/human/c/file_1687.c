#include<stdio.h>

int main(){

    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }

    int B[N];
    for (int i = 0; i < N; i++){
        scanf("%d", &B[i]);
    }

    int C[N-1];
    for (int i = 0; i < N-1; i++){
        scanf("%d", &C[i]);
    }

    int score = 0;

    for (int i = 0; i < N; i++){
        score += B[A[i]-1];

        if(i > 0 && A[i] == A[i-1] + 1){
            score += C[A[i-1]-1];
        }

        //printf("%d\n", score);
    }

    printf("%d", score);
    return 0;
}
