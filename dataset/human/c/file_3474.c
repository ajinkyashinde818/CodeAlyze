#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    intmax_t N, K, A[(int)2e5 + 1];
    intmax_t ans = 1, visited[(int)2e5 + 1] = {}, loop = 0;

    scanf("%jd%jd", &N, &K);
    for (size_t i = 1; i <= N; i++) {
        scanf("%jd", &A[i]);
    }

    for (size_t i = 1; i <= K; i++) {
        ans = A[ans];
        if (visited[ans]) {
            loop = i;
            break;
        } else {
            visited[ans] = i;
        }
    }

    if (loop != 0) {
        K -= visited[ans];
        K %= (loop - visited[ans]);
        for (size_t i = 0; i < K; i++) {
            ans = A[ans];
        }
    }

    printf("%jd\n", ans);

    return 0;
}
