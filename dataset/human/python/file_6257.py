Z = [0,1,2,3,4,5,5,4,3,2,1,1]
X=[0,1,2,3,4,5,6,7,8,9]
def solve_dp(s):
    n = len(s)
    s = [int(c) for c in s]
    inf = 10**9

    dp = [[inf] * 2 for _ in range(n)]

    d0 = s[0]
    dp[0][0] = Z[d0]
    dp[0][1] = Z[d0+1]

    for i in range(1, n):
        for j in range(2):
            d = s[i] + j
            for k in range(10):
                if d + X[k] >= 10:
                    dp[i][j] = min(dp[i][j], dp[i-1][1] + X[k] + Z[d + X[k] - 10])
                else:
                    dp[i][j] = min(dp[i][j], dp[i-1][0] + X[k] + Z[d + X[k]])

    return dp[n-1][0]

if __name__ == '__main__':
    s = input()
    print(solve_dp(s))
