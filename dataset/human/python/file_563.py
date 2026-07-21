def makelist(n, m):
    return [[0 for _ in range(m)] for _ in range(n)]

N = int(input())
A = [0] + list(map(int, input().split()))

dp = makelist(N+1, 2)
dp[1][0] = A[1]
dp[1][1] = -int(1e9)
for i in range(2, N+1):
    dp[i][0] = A[i] + max(dp[i-1][0], dp[i-1][1])
    dp[i][1] = -A[i] + max(dp[i-1][0] + (-A[i-1])*2, dp[i-1][1] + A[i-1]*2)

ans = max(dp[N][0], dp[N][1])
print(ans)
