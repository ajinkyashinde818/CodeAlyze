import sys
import itertools
input = sys.stdin.readline


def read_values():
    return map(int, input().split())


def read_list():
    return list(read_values())


def read_lists(N):
    return [read_list() for n in range(N)]


def f(n):
    if n < 2:
        return 1
    
    return n * f(n - 2)


def main():
    N = int(input())
    if N % 2 == 1:
        print(0)
        return

    N //= 2
    res = 0
    while N > 0:
        N //= 5
        res += N
    print(res)


if __name__ == "__main__":
    main()
