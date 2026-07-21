import fractions
from functools import reduce

n = int(input())

a = list(map(int,input().split()))

dp = [[a[0]],[-10**10]]

for i in range(n-1):
    dp[0].append(max(dp[0][i] +a[i+1], dp[1][i] + a[i+1]))
    dp[1].append(max(dp[0][i] - a[i+1]- 2*a[i], dp[1][i]-a[i+1] + 2*a[i]))

print(max(dp[0][n-1],dp[1][n-1]))
