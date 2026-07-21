#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N, D, X;

    scanf("%d%d%d", &N, &D, &X);

    int i, A;
    int sum = 0;

    for(i = 0; i < N; i ++){
        scanf("%d", &A);

        sum += (D - 1) / A + 1;
    }
    printf("%d", sum + X);
}
