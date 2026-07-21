#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int main(void) {
    int i, j, k;
    int n,a;
    int sum[101] = {0}, tmp[101][101] = {0}, max;

    scanf("%d", &n);

    max = -10000;
    for (i = 0; i < n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a);
            sum[j] = sum[j - 1] + a;
        }

        for (j = 1; j <= n; j++)
            for (k = j; k <= n; k++) {
                tmp[j][k] = max(tmp[j][k] + sum[k] - sum[j - 1], sum[k] - sum[j - 1]);
                max = max(max, tmp[j][k]);
            }
    }

    printf("%d\n", max);

    return 0;
}
