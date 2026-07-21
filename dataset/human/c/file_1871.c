#include<stdio.h>

int main(){
    int N;
    int A[20];
    int B[20];
    int C[20];
    int i;
    while(~scanf("%d",&N)){
        for(i = 0; i < N; i++)
            scanf("%d",&A[i]);
        for(i = 0; i < N; i++)
            scanf("%d",&B[i]);
        for(i = 0; i < N-1; i++)
            scanf("%d",&C[i]);
        int sum = B[A[N-1]-1];
        for(i = 0; i < N-1; i++){
            sum+=B[A[i]-1];
            if(A[i+1] - A[i] == 1){
                sum+=C[A[i]-1];
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
