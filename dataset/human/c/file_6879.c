#include <stdio.h>

int N;
int A[16][16];
long long dp[1 << 16];
long long G[1 << 16];

void to(long long *x, long long y) {
    if (*x < y) *x = y;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 1; i < 1 << N; i++) {
        dp[i] = -2e18;
        for (int j = 0; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if ((i >> j & 1) && (i >> k & 1)) {
                    G[i] += A[j][k];
                }
            }
        }
    }
    for (int i = 0; i < (1 << N); i++) {
        int s = ((1 << N) - 1) ^ i;
        for (int j = s; j != 0; j = (j - 1) & s) {
            to(&dp[i | j], dp[i] + G[j]);
        }
    }
    printf("%lld\n", dp[(1 << N) - 1]);
    return 0;
}
