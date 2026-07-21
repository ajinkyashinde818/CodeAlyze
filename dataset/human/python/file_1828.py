from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
from string import ascii_lowercase
from functools import lru_cache
import sys
sys.setrecursionlimit(10000)
INF = float("inf")
YES, Yes, yes, NO, No, no = "YES", "Yes", "yes", "NO", "No", "no"
dy4, dx4 = [0, 1, 0, -1], [1, 0, -1, 0]
dy8, dx8 = [0, -1, 0, 1, 1, -1, -1, 1], [1, 0, -1, 0, 1, 1, -1, -1]


def inside(y, x, H, W):
    return 0 <= y < H and 0 <= x < W


def ceil(a, b):
    return (a + b - 1) // b


def main():
    N, M = map(int, input().split())
    A, B = [], []
    for _ in range(N):
        A.append(input())
    for _ in range(M):
        B.append(input())

    for y in range(N - M + 1):
        for x in range(N - M + 1):
            ok = True
            for i in range(M):
                for j in range(M):
                    ok &= A[y + i][x + j] == B[i][j]

            if ok:
                print(Yes)
                return
    print(No)


if __name__ == '__main__':
    main()
