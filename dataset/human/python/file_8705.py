import sys


def input():
    return sys.stdin.readline().strip()


def main():
    K, N = map(int, input().split())
    A = list(map(int, input().split()))

    ans = [K - A[i] + A[i - 1] for i in range(1, N)]
    print(min(min(ans), A[-1] - A[0]))


if __name__ == "__main__":
    main()
