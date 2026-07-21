import sys, re, os
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians, gcd
from itertools import permutations, combinations, product, accumulate
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from functools import reduce
from bisect import bisect_left, insort_left
from heapq import heapify, heappush, heappop

INPUT = lambda: sys.stdin.readline().rstrip()
INT = lambda: int(INPUT())
MAP = lambda: map(int, INPUT().split())
S_MAP = lambda: map(str, INPUT().split())
LIST = lambda: list(map(int, INPUT().split()))
S_LIST = lambda: list(map(str, INPUT().split()))

sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7


def main():
    s = INPUT()
    t = INPUT()

    s = [ord(i) for i in sorted(s)]
    t = [ord(i) for i in sorted(t)]
    t.reverse()

    cnt = 0
    for x in s:
        if x < t[cnt]:
            print("Yes")
            sys.exit()
        elif x > t[cnt]:
            print("No")
            sys.exit()
        else:
            cnt += 1
            if cnt == len(t):
                print("No")
                sys.exit()

    print("Yes" if len(s) < len(t) else "No")


if __name__ == '__main__':
    main()
