#include <stdio.h>
#include <stdlib.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
typedef long long ll;

int main(void)
{
    int ans = 0;

    int k, n;
    scanf("%d%d", &k, &n);

    int a[n + 1];
    rep(i, n)
        scanf("%d", &a[i]);
    a[n] = k + a[0];

    int max = 0;
    rep(i, n)
        max = max(max, a[i + 1] - a[i]);

    printf("%d", k - max);

    return 0;
}
