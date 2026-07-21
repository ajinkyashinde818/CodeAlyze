def main():
    N = int(input())
    A = list(map(int, input().split()))

    dp = [[0, 0] for _ in range(N + 1)]
    dp[1] = [A[0], -A[0]]

    for i, n in enumerate(A[1:-1], start=2):
        dp[i][0] = max(dp[i - 1][0] + n, dp[i - 1][1] - n)
        dp[i][1] = max(dp[i - 1][0] - n, dp[i - 1][1] + n)

    dp[-1] = [dp[N - 1][0] + A[-1], dp[N - 1][1] - A[-1]]

    print(max(dp[-1]))


if __name__ == '__main__':
    main()
