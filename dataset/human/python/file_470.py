from sys import exit

N = int(input())
A = list(map(int, input().split()))

dp = [[0] * 2 for i in range(N + 1)]
dp[0][0] = 0
dp[0][1] = -10 ** 6

for i in range(N):
    dp[i + 1][0] = max(dp[i][0] + A[i], dp[i][1] - A[i])
    dp[i + 1][1] = max(dp[i][1] + A[i], dp[i][0] - A[i])

print(dp[N][0])
