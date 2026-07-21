import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
dp = [[0]*2 for _ in range(N)]
dp[0][1] = -10**18

for i in range(N-1):
    dp[i+1][0] = max(dp[i][0]+A[i], dp[i][1]-A[i])
    dp[i+1][1] = max(dp[i][0]-A[i], dp[i][1]+A[i])

print(max(dp[-1][0]+A[-1], dp[-1][1]-A[-1]))
