#include<stdio.h>

int main(void){
    int K, N, distance = 0, max_num = 0;
    scanf("%d %d",&K, &N);
    int A[N], difference[N];
    for(int i = 0; i < N; i++){
        scanf("%d",&A[i]);
    }
    for(int i = 1; i < N; i++){
        difference[i-1] = A[i] - A[i-1];
    }
    difference[N-1] = (K - A[N-1]) + A[0];

    for(int i = 1; i < N; i++){
        if(difference[i] > difference[max_num]){
            max_num = i;
        }
    }
    for(int i = 0; i < N; i++){
        distance += difference[i];
    }
    distance -= difference[max_num];
    printf("%d\n",distance);
    return 0;
}
