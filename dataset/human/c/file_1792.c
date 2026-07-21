#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

int main(void){
    int i,j,k;
    int N;
    int A[30],B[30],C[30];
    int answer = 0;
    
    scanf("%d",&N);
    for(i = 0;i < N-1;i++){
        scanf("%d\n",&A[i]);
    }
    scanf("%d",&A[i]);
    for(i = 0;i < N-1;i++){
        scanf("%d\n",&B[i]);
    }
    scanf("%d",&B[i]);
    for(i = 0;i < N-2;i++){
        scanf("%d\n",&C[i]);
    }
    scanf("%d",&C[i]);
    
    for(i = 0;i < N;i++){
        answer +=  B[A[i]-1];
        if(i != 0){
            if(A[i-1] == (A[i] - 1)){
                answer += C[A[i-1]-1];
            }
        }
    }
    
    printf("%d\n",answer);
    
    return 0;
}
