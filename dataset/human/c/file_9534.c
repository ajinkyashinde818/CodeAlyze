#include <stdio.h>

int main(void){
    int N, D, X;
    scanf("%d%d%d", &N, &D, &X);
    int A[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
        X += (D-1) / A[i] + 1;
    }
    printf("%d\n", X);
    return 0; 
}
