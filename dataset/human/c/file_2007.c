#include <stdio.h>

int main(int argc, char *argv[])
{
    long long A, B, C;
    long long ans = 0;

    scanf("%lld %lld %lld", &A, &B, &C);

    if (C > A + B) {
        ans = A + B + 1;
    } else {
        ans = C;
    }

    ans += B;

    printf("%lld\n", ans);

    return 0;
}
