from functools import reduce
from fractions import gcd
import math
import bisect
import itertools
import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline
INF = float("inf")


def main():
    K, N = map(int, input().split())
    A = list(map(int, input().split()))
    A.sort()

    res = INF
    for i in range(N):
        if i == N-1:
            res = min(res, A[N-1] - A[0])
        else:
            res = min(res, K - (A[i+1] - A[i]))
    
    print(res)


if __name__ == '__main__':
    main()
