#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

int main (int argc, char const *argv[])
{
    int64_t A, B, K;
    int64_t i, k = 0, ans = 0;

    scanf("%"PRId64"%"PRId64"%"PRId64, &A, &B, &K);

    i = A;

    while (k != K) {
        if ((A % i == 0) && (B % i == 0)) {
            k++;
            ans = i;
        }
        i--;
    }

    printf("%"PRId64"\n", ans);
}
