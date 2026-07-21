#include<stdio.h>
#define SIZE10 100000

typedef long long int ll;
typedef unsigned char u8;

int main(void){
    int A[100];
    int B[100];
    int C[100];
    int N = 0;
    int i = 0;
    int j = 0;
    int sum = 0;

    scanf("%d", &N);

    for(i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    for(i = 0; i < N; i++){
        scanf("%d", &B[i]);
    }
    for(i = 0; i < N-1; i++){
        scanf("%d", &C[i]);
    }

    sum = B[A[0]-1];

    for(i = 1; i < N; i++){
        if(A[i] - A[i-1] == 1){
            sum += C[A[i]-2]+B[A[i]-1];
        }else{
            sum += B[A[i]-1];
        }
    }

    printf("%d", sum);

    return 0;
}
