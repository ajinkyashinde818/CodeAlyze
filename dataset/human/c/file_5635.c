#include <stdio.h>
#define rep(i, n) for (i = 0; i < n; i++)

int main() {
    long long x;
    scanf("%lld", &x);

    long long ans = x / 11 * 2;
    if (x % 11 > 6) ans += 2;
    else if (x % 11 > 0) ans++;

    printf("%lld\n", ans);
    return 0;
}
