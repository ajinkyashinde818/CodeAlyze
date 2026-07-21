#include <stdio.h>

int main(void){

    int K = 0;
    int N = 0;
    int max = 0;

    scanf("%d %d", &K, &N);

    int A[N];
    int distance[N];

    for (int i = 0; i < N; i++){
        scanf("%d", &A[i]);

        if (i > 0){
            distance[i] = A[i] - A[i - 1];
        }
        if (distance[i] > max){
            max = distance[i];
        }
        //printf("max:%d\n", max);
    }
    distance[0] = (K - A[N - 1]) + A[0];

    if (distance[0] > max){
        max = distance[0];
    }
    max = K - max;

    printf("%d\n", max);

    return 0;
}
