def solve():
    def min2(x, y): return x if x <= y else y

    strN = '0' + input()

    Ns = list(map(int, strN))

    dp = [0, float('inf')]
    for Ni in reversed(Ns):
        dp2 = [0, 0]
        if Ni == 9:
            dp2[0] = dp[0] + Ni
        else:
            dp2[0] = min2(dp[0] + Ni, dp[1] + Ni + 1)
        dp2[1] = min2(dp[0] + 10 - Ni, dp[1] + 9 - Ni)
        dp = dp2

    print(dp[0])


solve()
