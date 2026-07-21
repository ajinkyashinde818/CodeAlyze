#include <stdio.h>
#include <math.h>

char c[1001][1001];
int dp[1001][1000];

int main(void) {
    int n, i, j, k, h, w, size, maximum;

    
    while (scanf("%d", &n) == 1 && n) {
        for (i = 1; i <= n; i++) {
            scanf("%s", c[i]);
        }
        for (i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }
        for (i = 1; i <= n; i++) {
            for (j = 0; j < n; j++) {
                if (c[i][j] == '.') {
                    dp[i][j] = dp[i-1][j] + 1;
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        for (i = n, maximum = 0; i > maximum; i--) {
            for (j = 0; j < n; j++) {
                h = dp[i][j];
                for (k = j, w = 1; k < n && w <= h; k++, w++) {
                    if (dp[i][k] < h) h = dp[i][k];
                    size = h < w ? h : w;
                    if (maximum < size) maximum = size;
                }
            }
        }
        printf("%d\n", maximum);
    }
    return 0;
}
