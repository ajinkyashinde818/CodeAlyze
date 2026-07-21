import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    n = input()
    l = len(n)

    dp = [[0] * 2 for _ in range(l + 1)]

    dp[0][1] = 1

    for i, d in enumerate(n, 1):
        di = int(d)
        dp[i][0] = min(dp[i - 1][1] + (10 - di), dp[i - 1][0] + di)
        dp[i][1] = min(dp[i - 1][1] + (10 - di - 1), dp[i - 1][0] + (di + 1))

    ans = min(dp[l][0], dp[l][1] + 1)

    print(ans)


if __name__ == '__main__':
    main()
