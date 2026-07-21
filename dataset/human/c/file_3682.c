#include <inttypes.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint64_t get_gcd(uint64_t a, uint64_t b)
{
    if (b == 0)
        return a;
    else
        return get_gcd(b, a % b);
}

uint64_t get_lcm(uint64_t a, uint64_t b)
{
    uint64_t g = get_gcd(a, b);
    return a / g * b;
}

int main(void)
{
    intmax_t A, B;
    intmax_t ans = 0;

    scanf("%jd%jd", &A, &B);

    ans = get_lcm(A, B);

    printf("%jd\n", ans);

    return 0;
}
