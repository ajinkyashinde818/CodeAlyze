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
    D, G = map(int, input().split())
    G //= 100

    P, C = [], []
    for _ in range(D):
        p, c = map(int, input().split())
        c //= 100
        P.append(p)
        C.append(c)

    dp = [[INF] * (2 * 10 ** 5 + 10) for _ in range(11)]
    dp[0][0] = 0
    for i in range(D):
        for j in range(len(dp[0])):
            if dp[i][j] == INF:
                continue

            for k in range(P[i] + 1):
                score = (i + 1) * k
                if k == P[i]:
                    score += C[i]
                dp[i + 1][j + score] = min(dp[i + 1][j + score], dp[i][j] + k)

    ans = INF
    for i in range(len(dp)):
        for j in range(len(dp[0])):
            if j >= G:
                ans = min(ans, dp[i][j])
    print(ans)


if __name__ == '__main__':
    main()
