import sys

input = sys.stdin.readline


def main():
    R, G, B, N = map(int, input().split())

    dp = [0] * (N + 1)
    dp[0] = 1
    for c in [R, G, B]:
        for i in range(N - c + 1):
            dp[i + c] += dp[i]

    ans = dp[N]
    print(ans)


if __name__ == "__main__":
    main()
