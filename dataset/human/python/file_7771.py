import sys

input = sys.stdin.readline


def main():
    N, K, S = map(int, input().split())

    if S == 10 ** 9:
        ans = [S] * K + [1] * (N - K)
    else:
        ans = [S] * K + [10 ** 9] * (N - K)

    print(" ".join(map(str, ans)))


if __name__ == "__main__":
    main()
