import sys

n = int(input())
As = list(map(int, input().split()))

Sc = list()

dp = [10**9] * (n-1)
ep = [10**9] * (n-1)
s = sum(As)

if n-2 == 0:
    print(abs(As[0] - As[1]))
    sys.exit()

for i in range(n-2):
    if i == 0:
        dp[i] = As[i]
    else:
        dp[i] = dp[i-1] + As[i]
    ep[i] = abs(dp[i] - s + dp[i])


print(min(ep))
