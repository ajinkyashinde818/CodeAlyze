import sys
from itertools import accumulate

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60
MOD = 1000000007


def main():
    N, *A = map(int, read().split())

    total = sum(A)
    ans = INF
    s = 0
    for i in range(N-1):
        s += A[i]
        if ans > abs(total - 2 * s):
            ans = abs(total - 2 * s)

    print(ans)
    return


if __name__ == '__main__':
    main()
