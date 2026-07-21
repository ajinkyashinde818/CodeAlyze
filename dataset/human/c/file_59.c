#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main (int argc, char const *argv[])
{
    int64_t R, G, B, N;
    int64_t ans = 0;

    scanf("%"PRId64"%"PRId64"%"PRId64"%"PRId64, &R, &G, &B, &N);

    for (int r = 0; r <= (N / R); r++) {
        for (int g = 0; g <= ((N - R * r) / G); g++) {
            if (((N - R * r - G * g) % B) != 0) continue;
            ans++;
        }
    }

    printf("%"PRId64"\n", ans);
}
