#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    intmax_t N, K, S;
    intmax_t A[(int)1e5] = {};

    scanf("%jd%jd%jd", &N, &K, &S);

    for (size_t i = 0; i < K; i++) {
        A[i] = S;
    }
    intmax_t padding;
    if (S == (int)1e9) {
        padding = 1;
    } else {
        padding = (int)1e9;
    }
    for (size_t i = K; i < N; i++) {
        A[i] = padding;
    }

    for (size_t i = 0; i < N; i++) {
        printf("%jd ", A[i]);
    }
    printf("\n");

    return 0;
}
