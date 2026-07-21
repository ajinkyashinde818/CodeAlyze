#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, m;
    int *a, *b;
    int i;
    int flag = 0;
    unsigned long int *dp;

    scanf("%d%d", &n, &m);

    a = calloc(m, sizeof(int));
    b = calloc(n, sizeof(int));
    dp = calloc(n + 1, sizeof(unsigned long int));

    for (i = 0; i < m; i++) {
        scanf("%d", &a[i]);
        b[a[i]] = 1;
    }

    if (b[1] == 0)
        dp[1] = 1;
    if (b[2] == 1)
        dp[2] = 0;
    else if (b[1] == 1)
        dp[2] = 1;
    else 
        dp[2] = 2;

    for (i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
        if (b[i] == 1)
            dp[i] = 0;
    }

    printf("%ld\n", dp[n]);

    return 0;
}
