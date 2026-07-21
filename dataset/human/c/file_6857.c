#include <stdio.h>

int main(void) {
    int n, i, j, l, r, v, maximum;
    int a[101] = {};
    int acc[101][101] = {};

    maximum = -999999999;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &v);
            a[j] = a[j-1] + v;
        }
        for (l = 1; l <= n; l++) {
            for (r = l; r <= n; r++) {
                acc[l][r] += a[r] - a[l-1];
                if (maximum < acc[l][r]) maximum = acc[l][r];
                if (acc[l][r] < 0) acc[l][r] = 0;
            }
        }
    }
    printf("%d\n", maximum);

    return 0;
}
