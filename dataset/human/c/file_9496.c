#include <stdio.h>
#include <stdlib.h>

int *init(int size, int init_value) {
    int *array = malloc(sizeof(int) * size);
    int i;
    for (i = 0; i < size; ++i) {
        *(array+i) = init_value;
    }
    return array;
}

int main()
{
    int N, D, X, i, j;
    if (scanf("%d", &N) < 0) return 1;
    if (scanf("%d", &D) < 0) return 1;
    if (scanf("%d", &X) < 0) return 1;

    int *A = malloc(sizeof(int) * N);
    int *P = init(N, 1);
    for (i = 0; i < N; ++i) {
        if (scanf("%d", A+i) < 0) return 1;
    }

    int count = 0;
    for (i = 1; i <= D; ++i) {
        for (j = 0; j < N; ++j) {
            if (P[j] == i) {
                count++;
                P[j] = P[j] + *(A+j);
            }
        }
    }
    printf("%d\n", X + count);
    return 0;
}
