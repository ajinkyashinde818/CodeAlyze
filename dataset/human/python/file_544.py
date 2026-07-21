from bisect import bisect_left, bisect_right
from collections import Counter, defaultdict, deque, OrderedDict
from copy import deepcopy
from fractions import gcd
from functools import lru_cache, reduce
from math import ceil, floor
from sys import setrecursionlimit

import heapq
import itertools
import operator


# globals
inf = float('inf')
N = 0
A = []


def set_inputs():
    global N, A
    N = get_int()
    A = get_li()
    return


def main():
    setrecursionlimit(100000)
    set_inputs()
    # ----------MAIN----------
    if 0 in A:
        print(sum(abs(a) for a in A))
    elif len(list(filter(lambda x: x < 0, A))) % 2 == 0:
        print(sum(abs(a) for a in A))
    else:
        m = min(abs(a) for a in A)
        print(sum(abs(a) for a in A) - 2 * m)
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
        return [types[0](input()) for _ in range(n)]
    return list(zip(*(
        [t(x) for t, x in zip(types, input().split(sep=sep))]
        for _ in range(n)
    )))


if __name__ == '__main__':
    main()
