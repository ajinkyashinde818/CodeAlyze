#include <stdio.h>

int main(void)
{
    long long int MOD = 1000000007;
    int n, m, a;
    int i;

    scanf("%d%d", &n, &m);
    long long int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (i = 2; i < n + 1; i++)
        dp[i] = -1;
    for (i = 0; i < m; i++)
    {
        scanf("%d", &a);
        dp[a] = 0;
    }

    for (i = 2; i < n + 1; i++)
        if (dp[i] == -1)
            dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;

    printf("%lld\n", dp[n]);

    return 0;
}
