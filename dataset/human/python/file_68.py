import bisect
import heapq
import itertools
import math
import operator
import os
import re
import string
import sys
from collections import Counter, deque, defaultdict
from copy import deepcopy
from decimal import Decimal
from fractions import gcd
from functools import lru_cache, reduce
from operator import itemgetter, mul, add, xor

import numpy as np

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(10 ** 9)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7
# MOD = 998244353

# N = int(sys.stdin.readline())
# P = [int(sys.stdin.readline()) for _ in range(N)]
#
# P = np.array(P, dtype=int)
#
# ans = 0
# while np.all(P % 10 == 0):
#     P //= 10
#     ans += 1
# print(ans)

R, G, B, N = list(map(int, sys.stdin.readline().split()))

ans = 0
for r in range(0, N + 1, R):
    for g in range(0, N + 1 - r, G):
        b = N - r - g
        if b == 0 or b > 0 and b % B == 0:
            ans += 1
print(ans)
