import sys

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

N = [int(x)-48 for x in read().rstrip()]

ans = 0

dp = [[0]*(len(N)+1) for i in range(2)]


dp[1][0] = 1
dp[0][0] = 0


for i in range(1, len(N)+1):
    dp[0][i] = min(dp[0][i-1] + N[i-1],
                   dp[1][i-1] + (10 - N[i-1]))

    dp[1][i] = min(dp[0][i-1] + N[i-1] + 1,
                   dp[1][i-1] + (10 - (N[i-1] + 1)))


print(dp[0][len(N)])
