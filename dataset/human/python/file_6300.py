import sys
input = sys.stdin.readline
S = [0] + list(map(int, list(input())[: -1]))

dp = [[float("inf")] * 2 for _ in range(len(S) + 1)]
dp[-1][0] = 0
for i in range(len(dp) - 1, 0, -1):
  for j in range(2):
    if S[i - 1] + j <= 5:
      dp[i - 1][0] = min(S[i - 1] + j + dp[i][j], dp[i - 1][0])
    if S[i - 1] + j >= 5:
      dp[i - 1][1] = min(10 - (S[i - 1] + j) + dp[i][j], dp[i - 1][1])

print(min(dp[0]))
