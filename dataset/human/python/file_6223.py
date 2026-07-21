def main():
    a = list(map(int, list(input())))
    n = len(a)
    dp = [[0, 0] for _ in [0]*(n+1)]
    dp[0][1] = 1
    for i in range(n):
        dp[i+1][0] = min(dp[i][0]+a[i], dp[i][1]+10-a[i])
        dp[i+1][1] = min(dp[i][0]+a[i]+1, dp[i][1]+9-a[i])
    print(dp[n][0])

main()
