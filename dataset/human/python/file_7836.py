import sys


def input():
    return sys.stdin.readline().strip()


sys.setrecursionlimit(10 ** 9)


def main():
    N, K, S = map(int, input().split())
    A = [S for _ in range(K)]
    if S != 10 ** 9:
        B = [S + 1 for _ in range(N - K)]
    else:
        B = [S - 1 for _ in range(N - K)]
    C = A + B
    print(*C, sep=" ")


if __name__ == "__main__":
    main()
