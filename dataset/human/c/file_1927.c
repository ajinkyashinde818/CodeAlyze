#include <stdio.h>

int main(void){
    int N;
    int A[21];
    int B[51];
    int C[51];
    int satis=0;
    int num=-1;
    int i;
    scanf("%d",&N);
    for(i=1; i<=N; i++){
        scanf("%d",&A[i]);
    }
    for(i=1; i<=N; i++){
        scanf("%d",&B[i]);
    }
    for(i=1; i<=N-1; i++){
        scanf("%d",&C[i]);
    }
    for(i=1; i<=N; i++){
        satis += B[A[i]];
        if(num+1 == A[i]){
            satis += C[A[i]-1];
        }
        num = A[i];
    }
    printf("%d",satis);
}
