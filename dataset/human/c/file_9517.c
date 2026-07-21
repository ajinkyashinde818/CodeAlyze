#include <stdio.h>

int main() {
    int i, j, N, D, X, A, eaten = 0;

    scanf("%d%d%d", &N, &D, &X);
    for (i=0; i < N ;i++) {
        scanf("%d", &A);
        for (j=1; j <= D ;j+=A) {
            // printf("    %d %d\n", i, j);
            eaten++;
        }
    }
    printf("%d\n", eaten + X);
    return 0;
}
