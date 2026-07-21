import math, sys
from bisect import bisect_left, bisect_right
from collections import Counter, defaultdict, deque
from copy import deepcopy
from functools import lru_cache
from heapq import heapify, heappop, heappush
from itertools import accumulate, combinations, permutations
input = sys.stdin.readline
mod = 10**9 + 7
ns = lambda: input().strip()
ni = lambda: int(input().strip())
nm = lambda: map(int, input().split())
nl = lambda: list(map(int, input().split()))

n = ni()
A = nl()

abstotal = sum([abs(i) for i in A])
absmin = min([abs(i) for i in A])
if len([i for i in A if i < 0]) % 2 == 0:
    ans = abstotal
else:
    ans = abstotal - 2 * absmin
print(ans)
