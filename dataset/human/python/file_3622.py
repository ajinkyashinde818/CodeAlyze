import sys

sys.setrecursionlimit(1000000)

import bisect
import math
import collections
import heapq

def factrization(N):
    k = 2
    ret = {}
    L = N ** 0.5
    while k < L:
        if N % k == 0:
            ret.setdefault(k, 0)
            ret[k] += 1
            N //= k
        else:
            k += 1
    if N > 1:
        ret.setdefault(N, 0)
        ret[N] += 1
    return ret
#
# print(factrization(64))
# print(factrization(24))
# print(factrization(1000000007))
# print(factrization(997764507000))

def solve(N):
    f = factrization(N)
    ans = 0
    for n in f.values():
        i = 1
        while i <= n:
            n -= i
            i += 1
            ans += 1
    return ans
#
# print(solve(64))
# print(solve(24))
# print(solve(1))
# print(solve(1000000007))
# print(solve(997764507000))

if __name__ == "__main__":
    N = int(input())
    print(solve(N))
