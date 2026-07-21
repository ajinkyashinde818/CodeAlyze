from bisect import bisect_left, bisect_right
from collections import Counter, defaultdict, deque, OrderedDict
from copy import deepcopy
from fractions import gcd
from functools import lru_cache, reduce
from math import ceil, floor
from sys import setrecursionlimit

import heapq as hq
import itertools as its
import operator as op


# globals
inf = float('inf')
N = 0


def set_inputs():
    global N
    return


def main():
    setrecursionlimit(100000)
    set_inputs()
    # ----------MAIN----------
    r, g, b, n = get_li()
    ans = 0
    for x in range(n // r + 1):
        for y in range(n // g + 1):
            z = n - r * x - g * y
            if z % b != 0 or z < 0:
                continue
            ans += 1
    print(ans)
    return


def get_int():
    return int(input())


def get_float():
    return float(input())


def get_str():
    return input().strip()


def get_li():
    return [int(i) for i in input().split()]


def get_lf():
    return [float(f) for f in input().split()]


def get_lc():
    return list(input().strip())


def get_data(n, types, sep=None):
    if len(types) == 1:
        return [types[0](input().strip()) for _ in range(n)]
    return list(zip(*(
        [t(x) for t, x in zip(types, input().strip().split(sep=sep))]
        for _ in range(n)
    )))


if __name__ == '__main__':
    main()
