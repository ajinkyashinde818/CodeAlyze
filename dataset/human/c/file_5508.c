#include <stdio.h>
#define N 1000000
char p[N];
long long dp[10001];
int main(void)
{
    int i, j;
    for (i=2; i<N; ++i) p[i]=1;
    for (i=2; i*i<N; ++i) if (p[i])
        for (j=2*i; j<N; j+=i) p[j]=0;

    dp[1]=2;
    j=2;
    for (i=3; i<N; ++i) if (p[i]) {
        dp[j]=dp[j-1]+i;
        j++;
        if (j>10000) break;
    }

    while (scanf("%d", &j), j) printf("%lld\n", dp[j]);
    return 0;
}
