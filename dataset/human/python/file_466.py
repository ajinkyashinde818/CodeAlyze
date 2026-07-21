import numpy as np
import sys
n = int(input())
a = np.array([int(x) for x in input().split()])
dp = np.zeros((n + 1, 2))
dp[0][1] = -2000000001
for i in range(n):
	dp[i + 1][0] = max(dp[i][0] + a[i], dp[i][1] - a[i])
	dp[i + 1][1] = max(dp[i][0] - a[i], dp[i][1] + a[i])
print(int(dp[n][0]))
