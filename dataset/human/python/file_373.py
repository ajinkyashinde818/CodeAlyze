import sys

N = int(input())
a_list = list(map(int, input().split()))

dp = [[0] * 2 for _ in range(N + 1)]
dp[0][0] = 0
dp[0][1] = -sys.maxsize

for i in range(N):
    dp[i + 1][0] = max(dp[i][0] + a_list[i], dp[i][1] - a_list[i])
    dp[i + 1][1] = max(dp[i][0] - a_list[i], dp[i][1] + a_list[i])
print(dp[N][0])
