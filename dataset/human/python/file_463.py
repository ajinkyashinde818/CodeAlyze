def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    dp = [[0,0] for _ in range(n+1)]
    dp[0][0] = 0
    dp[0][1] = -float("inf")
    for i in range(n):
        dp[i+1][0] = max(dp[i][0]+a[i],dp[i][1]-a[i])
        dp[i+1][1] = max(dp[i][0]-a[i],dp[i][1]+a[i])
    print(dp[n][0])
    
if __name__ == "__main__":
    main()
