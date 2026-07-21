import numpy as np

n = int(input())
A = list(map(int, input().split()))

dp = [[0, 0] for i in range(n+1)]
dp[0][1] = -np.inf

for i in range(n):
    dp[i+1][0] = max(dp[i][0] + A[i], dp[i][1] - A[i])
    dp[i+1][1] = max(dp[i][0] - A[i], dp[i][1] + A[i])

print(dp[n][0])
