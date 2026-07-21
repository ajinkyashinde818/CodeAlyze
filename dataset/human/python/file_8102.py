import sys
import re
import math
import collections
import decimal
import bisect
import itertools
import fractions
import functools
import copy
import heapq
import decimal

sys.setrecursionlimit(10000001)
INF = sys.maxsize
MOD = 10 ** 9 + 7

ni = lambda: int(sys.stdin.readline())
ns = lambda: map(int, sys.stdin.readline().split())
na = lambda: list(map(int, sys.stdin.readline().split()))


# ===CODE===
def main():
    k, s = ns()
    ans = 0
    for x in range(k + 1):
        for y in range(k + 1):
            if k >= s - x - y >= 0:
                ans += 1
    print(ans)

if __name__ == '__main__':
    main()
