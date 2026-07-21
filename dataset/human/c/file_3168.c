#include <stdio.h>

int main(){
//int A[20001];
    int K,N;
    int i;
    int distance;
    int max;

    max = 0;

    scanf("%d %d",&K,&N);
    int A[N];

    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    for(i=0;i<N-1;i++){
        distance = A[i+1] - A[i];
        if(distance>=max){
            max = distance;
        }
    }
    distance = K - A[N-1] + A[0];
        if(distance>=max){
            max = distance;
        }

    printf("%d",K-max);
    return 0;
}
