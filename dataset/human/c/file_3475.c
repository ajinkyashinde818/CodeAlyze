#include <stdio.h>

long long int f[200001] = {}, a[200001], k, i, n, p;

int main() {
    scanf("%lld %lld", &n, &k);
    for (int j = 1; j <= n; j++) scanf("%lld", &a[j]);
    for (p = i = 1; i <= k; p = a[p], i++)
        if (f[p]) k = i + (k - i) % (i - f[p]);
        else f[p] = i;
    printf("%lld", p);
    return 0;
}
