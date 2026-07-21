#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    intmax_t N, M, X, C[12], A[12][12];
    intmax_t ans = INTMAX_MAX;

    scanf("%jd%jd%jd", &N, &M, &X);
    for (size_t i = 0; i < N; i++) {
        scanf("%jd", &C[i]);
        for (size_t j = 0; j < M; j++) {
            scanf("%jd", &A[i][j]);
        }
    }

    for (uint16_t a = 1; a <= ((1 << N) - 1); a++) {
        intmax_t level[12] = {}, cost = 0;
        bool achieve = true;
        for (size_t i = 0; i < N; i++) {
            if (a & (1 << i)) {
                cost += C[i];
                for (size_t j = 0; j < M; j++) {
                    level[j] += A[i][j];
                }
            }
        }
        for (size_t j = 0; j < M; j++) {
            if (level[j] < X) {
                achieve = false;
            }
        }
        if (achieve) {
            if (cost < ans) {
                ans = cost;
            }
        }
    }

    if (ans == INTMAX_MAX) {
        ans = -1;
    }

    printf("%jd\n", ans);

    return 0;
}
