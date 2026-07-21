import itertools
import math
import sys
import heapq
from collections import Counter
from collections import deque
from fractions import gcd
from functools import reduce
sys.setrecursionlimit(4100000)
from functools import lru_cache
INF = 1 << 60

#ここから書き始める
n, r = map(int, input().split())
if n >= 10:
    print(r)
else:
    print(r + 100 * (10 - n))
