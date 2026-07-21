#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    int64_t A[N];
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    int64_t dp[N][2];
    dp[0][0] = A[0];
    dp[0][1] = INT32_MIN;
    for (int i = 1; i < N; ++i) {
        dp[i][0] = std::max(dp[i-1][0] + A[i], dp[i-1][1] + A[i]);
        dp[i][1] = std::max(dp[i-1][0] - 2 * A[i-1] - A[i], dp[i-1][1] + 2 * A[i-1] - A[i]);
    }

    std::printf("%ld\n", std::max(dp[N-1][0], dp[N-1][1]));

    return 0;
}
