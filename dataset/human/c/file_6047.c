#include <stdio.h>
int main(void)
{
    int i, n;
    long long num, min, maxv;

    min = 2000000000;
    maxv = 1 - min;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%lld", &num);
        maxv = num - min > maxv ? num - min : maxv;
        min = num < min ? num : min;
    }
    printf("%lld\n", maxv);
    return 0;
}
