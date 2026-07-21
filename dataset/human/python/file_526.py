import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

N = int(input())
As = list(mapint())

dp = [[0]*2 for _ in range(N)]
# -, +
dp[0][0] = -As[0]
dp[0][1] = As[0]
for i in range(1, N-1):
    a = As[i]
    dp[i][0] = max(dp[i-1][0]+a, dp[i-1][1]-a)
    dp[i][1] = max(dp[i-1][0]-a, dp[i-1][1]+a)

dp[-1][0] = dp[-2][0]-As[-1]
dp[-1][1] = dp[-2][1]+As[-1]

print(max(dp[-1]))
