#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    intmax_t N, M;

    scanf("%jd%jd", &N, &M);

    if (N == M) {
        puts("Yes");
    } else {
        puts("No");
    }

    return 0;
}
