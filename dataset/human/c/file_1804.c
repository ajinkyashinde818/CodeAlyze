#include <stdio.h>

int main(void){

    //input
    int N;  scanf("%d",&N);
    int A[N];
    for(int i = 0; i < N; ++i){
        scanf("%d",&A[i]);
        --A[i];                     //配列は0から始まるため
    }
    int B[N];
    for(int i = 0; i < N; ++i){
        scanf("%d",&B[i]);
    }
    int C[N-1];
    for(int i = 0; i< N-1; ++i){
        scanf("%d",&C[i]);
    }
    
    int sum = 0;

    //calc
    
    for(int i=0; i<N; ++i){
        sum += B[A[i]];
        if(i > 0 && A[i] == A[i-1]+1){
            sum += C[A[i-1]];
        }
    }

    printf("%d",sum);
}
