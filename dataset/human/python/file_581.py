import numpy as np
N = int(input())
A_list = list(map(int, input().split()))

dp = np.zeros((len(A_list)+1, 2))
dp[0][1] = - 10**5

for idx, a in enumerate(A_list):
    dp[idx+1][0] = max(dp[idx][0] + a, dp[idx][1] - a)
    dp[idx+1][1] = max(dp[idx][0] - a, dp[idx][1] + a)
print(int(dp[N][0]))
