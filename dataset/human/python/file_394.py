def d_flipping_signs_dp(N, A):
    dp = [[0] * 2 for _ in range(N + 1)]
    dp[0][0] = 0
    dp[0][1] = -float('inf')
    for i in range(N):
        dp[i + 1][0] = max(dp[i][0] + A[i], dp[i][1] - A[i])
        dp[i + 1][1] = max(dp[i][0] - A[i], dp[i][1] + A[i])
    return dp[N][0]

N = int(input())
A = [int(i) for i in input().split()]
print(d_flipping_signs_dp(N, A))
