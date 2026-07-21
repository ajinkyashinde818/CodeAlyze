#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
    if (*(intmax_t *)a < *(intmax_t *)b)
        return -1;
    if (*(intmax_t *)a > *(intmax_t *)b)
        return 1;
    return 0;
}

int main(void)
{
    intmax_t K, N, A[(int)2e5];
    intmax_t d[(int)2e5], ans = 0;

    scanf("%jd%jd", &K, &N);
    for (size_t i = 0; i < N; i++) {
        scanf("%jd", &A[i]);
    }

    qsort(A, N, sizeof(A[0]), compare);

    d[0] = (K - A[N - 1]) + A[0];
    for (size_t i = 1; i < N; i++) {
        d[i] = A[i] - A[i - 1];
    }

    for (size_t i = 0; i < N; i++) {
        if (d[i] > ans)
            ans = d[i];
    }

    printf("%jd\n", K - ans);

    return 0;
}
