import numpy as np
N = int(input())
A = list(map(int, input().split()))

dp = np.zeros((N+1, 2), dtype=int)
dp[0, 1] = -10**9

for i in range(N):
    dp[i+1, 0] = max(dp[i, 0] + A[i], dp[i, 1] - A[i])
    dp[i+1, 1] = max(dp[i, 0] - A[i], dp[i, 1] + A[i])
print(dp[N, 0])
