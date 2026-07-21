#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

int main (int argc, char const *argv[])
{
    int64_t N, A;
    int64_t ans = 0, num = 0, min = (int)1e9;

    scanf("%"PRId64, &N);
    for (int i = 0; i < N; i++) {
        scanf("%"PRId64, &A);
        ans += llabs(A);
        if (A < 0) num++;
        if (llabs(A) < min) min = llabs(A);
    }

    printf("%"PRId64"\n", (num % 2) ? (ans - min * 2) : ans);
}
