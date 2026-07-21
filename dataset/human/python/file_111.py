def trans(n, dp, color):
    for i in range(n-color+1):
        dp[i+color] += dp[i]
    return dp

def main():
    r, g, b, n = [int(i) for i in input().split()]
    dp = [0 for i in range(n+1)]
    dp[0] = 1
    dp = trans(n, dp, r)
    dp = trans(n, dp, g)
    dp = trans(n, dp, b)
    print(dp[-1])

main()
