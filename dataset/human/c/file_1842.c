#include<stdio.h>

int main(void){
    
    int N,A[20],B[20],C[20],i,ans = 0;

    scanf("%d",&N);
    for(i = 0;i < N;i++){
        scanf("%d",&A[i]);
    }
    for(i = 0;i < N;i++){
        scanf("%d",&B[i]);
    }
    for(i = 0;i < N - 1;i++){
        scanf("%d",&C[i]);
    }

    for(i = 0;i < N;i++){
        ans += B[A[i]-1];
        //printf("%d 追加 ans:%d\n",B[A[i]-1],ans);
        if(A[i] -  1 == A[i - 1]){
            ans += C[A[i - 1]-1];
            //printf("Cの %d 追加 ans:%d\n",C[A[i-1]-1],ans);
        }
    }

    printf("%d\n",ans);
    return 0;
}
