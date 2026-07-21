#include <stdio.h>
#include <string.h>

int c[15], a[15][15];

int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    }
    int ans = -1;
    for (int i = 1; i < (1 << n); i++) {
        int cs = 0, sum[15];
        memset(sum, 0, 15 * sizeof(int));
        for (int j = 0; j < n; j++)
            if (i & (1 << j)) {
                cs += c[j];
                for (int k = 0; k < m; k++)
                    sum[k] += a[j][k];
            }
        int ok = 1;
        for (int j = 0; j < m; j++)
            if (sum[j] < x) ok = 0;
        if (ok && (ans == -1 || ans > cs)) ans = cs;
    }
    printf("%d\n", ans);
}
