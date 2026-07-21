#include <stdio.h>
int main(void) {
    int n, d, x, a[200];
    int ans = 0;
    int i, j, k;

    scanf("%d", &n);
    scanf("%d %d", &d, &x);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    for (i = 0; i < n; i++) {
        for (j = 1; j <= d; j += a[i]) ans++;
    }
    ans += x;
    printf("%d\n", ans);
    return 0;
}
