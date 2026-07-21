import math
import sys
import collections
import bisect
readline = sys.stdin.readline


def main():
    k, n = map(int, readline().rstrip().split())
    A = sorted(list(map(int, readline().rstrip().split())))
    maxA = k + A[0] - A[n-1]
    for i in range(n-1):
        a = abs(A[i+1] - A[i])
        maxA = max(maxA, a)
    print(k - maxA)


if __name__ == '__main__':
    main()
