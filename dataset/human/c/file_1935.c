#include<stdio.h>

int main(){
    int N,A[21],B[21],C[21];
    int i,sum=0;
    scanf("%d",&N);
    for(i = 1 ; i <= N ; i++){
        scanf("%d",&A[i]);
    }
    for(i = 1 ; i <= N ; i++){
        scanf("%d",&B[i]);
    }
    for(i = 1 ; i <= N-1 ; i++){
        scanf("%d",&C[i]);
    }
    C[N] = 0;
    sum += B[A[1]];
    for(i = 2 ; i <= N ; i++){
        if(A[i-1] == A[i] - 1){
            sum += B[A[i]] + C[A[i-1]];
        }else{
            sum += B[A[i]];
        }
    }
    printf("%d",sum);
    return 0;
}
