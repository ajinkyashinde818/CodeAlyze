def main():
  n=int(input())
  a=list(map(int,input().split()))
  dp=[0,-10**18]
  for i in range(n-1):
    dp2=[max(dp[0]+a[i],dp[1]-a[i]),max(dp[0]-a[i],dp[1]+a[i])]
    dp=dp2
  print(max(dp[0]+a[-1],dp[1]-a[-1]))
main()
