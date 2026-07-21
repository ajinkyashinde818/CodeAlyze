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
    N, K = map(int, input().split())
    A = list(map(lambda x: int(x) - 1, input().split()))

    visited = [False] * N
    route = []
    
    cnt = 0
    v = 0
    while visited[v] == False and cnt < K:
        visited[v] = True
        route.append(v)
        v = A[v]
        cnt += 1

    if cnt < K:
        start = route.index(v)
        loop = cnt - start
        offset = (K - start) % loop
        res = route[start + offset] + 1
        print(res)
        # print(cnt)
        # print(offset)
    else:
        print(v + 1)


if __name__ == '__main__':
    main()
