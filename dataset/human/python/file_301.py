from sys import stdin, setrecursionlimit
from bisect import bisect_right


def main():
    input = stdin.buffer.readline
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()

    idx = bisect_right(a, 0)

    if idx % 2 == 0:
        print(sum(a[idx:]) - sum(a[:idx]))
    elif idx == n:
        print(a[idx - 1] - sum(a[:idx - 1]))
    else:
        print(sum(a[idx:]) - sum(a[:idx]) - 2 * min(-a[idx - 1], a[idx]))


if __name__ == "__main__":
    setrecursionlimit(10000)
    main()
