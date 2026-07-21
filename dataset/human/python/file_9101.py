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

sys.setrecursionlimit(2147483647)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7

S = sys.stdin.readline().rstrip()
dp = [False] * (len(S) + 100)
dp[0] = True
words = ['dreamer', 'dream', 'erase', 'eraser']
for i in range(len(S)):
    if dp[i]:
        for w in words:
            dp[i + len(w)] |= S.startswith(w, i)
if dp[len(S)]:
    print('YES')
else:
    print('NO')
