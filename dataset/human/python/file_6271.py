import sys

ns = sys.stdin.readline().strip()
ns = ns[::-1]
ns += '0'
ns_arr = list(ns)
n_arr = [int(s) for s in ns_arr]
nl = len(n_arr)

dp = [[float('inf')] * (nl+1) for _ in range(2)]

dp[0][0] = 0

for j in range(nl):
    for i in range(2):
        num = n_arr[j]
        num += i

        if num < 10:
            dp[0][j+1] = min(dp[0][j+1], dp[i][j] + num)

        if num > 0:
            dp[1][j+1] = min(dp[1][j+1], dp[i][j] + (10 - num))

ans = dp[0][nl]
print(ans)
