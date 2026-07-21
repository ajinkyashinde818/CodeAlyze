#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    intmax_t N, R;

    scanf("%jd%jd", &N, &R);

    if (N >= 10) {
        printf("%jd\n", R);
    } else {
        printf("%jd\n", R + 100 * (10 - N));
    }

    return 0;
}
