import sys
import itertools
input = sys.stdin.readline


def read_values():
    return map(int, input().split())


def read_list():
    return list(read_values())


def read_lists(N):
    return [read_list() for n in range(N)]


def f(A):
    min_num = A[0] + A[-1]


def main():
    N, K, S = read_values()
    L = [S] * K
    L += ([S + 1] if S != 10 ** 9 else [1]) * (N - K)
    print(" ".join(map(str, L)))


if __name__ == "__main__":
    main()
