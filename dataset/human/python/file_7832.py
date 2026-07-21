import sys

sys.setrecursionlimit(10 ** 6)
INF = float("inf")
MOD = 10 ** 9 + 7


def input():
    return sys.stdin.readline().strip()


def main():
    N, K, S = map(int, input().split())
    MAX = 10 ** 9

    ans = []
    if S == MAX:
        ans += [S] * K
        ans += [1] * (N - K)
    else:
        ans += [S] * K
        ans += [MAX] * (N - K)

    print(*ans, sep=" ")


if __name__ == "__main__":
    main()
