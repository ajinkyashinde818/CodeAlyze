import sys
input =sys.stdin.readline
def solve():
  s = input().rstrip()
  n = len(s)
  dp = [[float("Inf")]*2 for _ in range(n+1)]
  dp[0][0] = 0
  dp[0][1] = 1

  for i in range(0,n):
    number = int(s[i])

    dp[i+1][0] = min([dp[i][0]+number,dp[i][0]+(10-number)+1,dp[i+1][0]])
    if number != 9:
      dp[i+1][1] = min([dp[i][0]+number+1,dp[i][0]+(10-number),dp[i+1][1]])
     
    dp[i+1][0] = min(dp[i][1] +(10-number),dp[i+1][0])
    dp[i+1][1] = min(dp[i][1] + (10-number-1),dp[i+1][1])
        
  #print(dp)
  print(min(dp[n][0],dp[n][1]+1))
solve()
