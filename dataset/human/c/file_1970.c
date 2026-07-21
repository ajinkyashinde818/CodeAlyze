#include <stdio.h>
int main(void){
    // Your code here!
    int N,A[25],B[50],C[50],sum=0;
    scanf("%d",&N);
    for(int i=1;i <= N;i++){
        scanf("%d",&A[i]);
    }
    for(int i=1;i <= N;i++){
        scanf("%d",&B[i]);
    }
    for(int i=1;i <= N-1;i++){
        scanf("%d",&C[i]);
    }
    
    for(int i = 1;i <= N;i++){
        sum+=B[i];
        if(A[i+1]-A[i] == 1){
            sum+=C[A[i]];
        }
    }
    printf("%d",sum);
}
