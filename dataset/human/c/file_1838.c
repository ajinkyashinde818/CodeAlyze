#include<stdio.h>

int main(void){
    int N;
    scanf("%d",&N);
    int A[N],B[N],C[N-1];
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    for(int i=0;i<N;i++){
        scanf("%d",&B[i]);
    }
    for(int i=0;i<N-1;i++){
        scanf("%d",&C[i]);
    }

    int score = B[A[0]-1];
        

    for(int i=1;i<N;i++){
        score += B[A[i]-1];
        if(A[i]==A[i-1]+1){
            score += C[A[i-1]-1];
        }
    }
    printf("%d",score);
    return 0;
}
