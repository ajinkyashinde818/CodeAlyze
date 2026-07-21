import sys
MAX_INT = int(10e15)
MIN_INT = -MAX_INT
mod = 1000000007
sys.setrecursionlimit(1000000)
def IL(): return list(map(int,input().split()))
def SL(): return input().split()
def I(): return int(sys.stdin.readline())
def S(): return input()

s = S()
t = s[::-1]
N = len(s)

dp = [[MAX_INT]*2 for i in range(N+1)]
dp[0][0] = 0
for i in range(N):
  num = int(t[i])
  dp[i+1][0] = min(dp[i][0] + num, dp[i][1] + num +1)
  dp[i+1][1] = min(dp[i][0] + 10-num, dp[i][1] + 10-num-1)
print(min(dp[-1][0], dp[-1][1]+1))
