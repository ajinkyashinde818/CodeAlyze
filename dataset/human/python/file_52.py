import numpy as np

IN = input().split()

dp = np.zeros((4,3001))
dp[0][0] = 1

for i in range(3):
    for j in range(3001):
        dp[i+1][j] += dp[i][j]
    for j in range(3001):
        if(j - int(IN[i]) >= 0):
            dp[i+1][j] += dp[i+1][j - int(IN[i])]

print(int(dp[3][int(IN[3])]))
