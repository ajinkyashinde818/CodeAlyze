import re
import sys
from fractions import gcd
from functools import reduce
from itertools import product

import numpy as np

sys.setrecursionlimit(200000)


def input():
    return sys.stdin.readline()[:-1]


def ii(t: type = int):
    return t(input())


def il(t: type = int):
    return list(map(t, input().split()))


def imi(N: int, t: type = int):
    return [ii(t) for _ in range(N)]


def iml(N: int, t: type = int):
    return [il(t) for _ in range(N)]


def solve():
    N = ii()
    A = np.asarray(il())
    B = A[A < 0]
    if len(B) % 2 == 0:
        return sum(np.abs(A))
    sorted_A = sorted(np.abs(A))
    return sum(sorted_A[1:]) - sorted_A[0]


if __name__ == "__main__":
    print(solve())
