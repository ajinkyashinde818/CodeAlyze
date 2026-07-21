import sys
IS = lambda: sys.stdin.readline().rstrip()
II = lambda: int(IS())
MII = lambda: list(map(int, IS().split()))

def main():
    n = II()
    aa = MII()
    dp = [[0]*(2) for _ in range(n)]
    dp[0][0] = aa[0]
    dp[0][1] = -aa[0]
    for i in range(1, n):
        dp[i][0] = max(dp[i-1][0]+aa[i], dp[i-1][1]-aa[i])
        dp[i][1] = max(dp[i-1][0]-aa[i], dp[i-1][1]+aa[i])
    print(max(dp[n-2][0]+aa[-1], dp[n-2][1]-aa[-1]))

if __name__ == '__main__':
    main()
