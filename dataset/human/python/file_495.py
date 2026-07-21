from _collections import deque
from _ast import Num


def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield (number)


input_parser = parser()


def gw():
    global input_parser
    return next(input_parser)


def gi():
    data = gw()
    return int(data)


MOD = int(1e9 + 7)

import numpy
from collections import deque
from math import sqrt
from math import floor
# https://atcoder.jp/contests/abc114/tasks/abc114_c
# C - 755
"""
need to consider the case that ticket is not enough to lower everything
"""

N = gi()
nps = []
ns = []

for i in range(N):
    a = gi()
    if a < 0:
        ns.append(-a)
    else:
        nps.append(a)

ns.sort()
nps.sort()

base = sum(ns) + sum(nps)

if len(ns) % 2:
    ans = base - 2 * ns[0]
    if len(nps):
        ans = max(ans, base - 2 * nps[0])
else:
    ans = base

print(ans)
