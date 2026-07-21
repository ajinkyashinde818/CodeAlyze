#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(void){

    int N, D, X;

    scanf("%d%d%d", &N, &D, &X);

    int A[N];
    int ans = X;

    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
        ans += (D-1) / A[i] + 1;
    }

    printf("%d\n", ans);

    return 0;
}
