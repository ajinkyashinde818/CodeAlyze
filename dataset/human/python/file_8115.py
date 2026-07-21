import sys
import math
import itertools
import collections
import heapq
import re
import numpy as np
from functools import reduce

rr = lambda: sys.stdin.readline().rstrip()
rs = lambda: sys.stdin.readline().split()
ri = lambda: int(sys.stdin.readline())
rm = lambda: map(int, sys.stdin.readline().split())
rl = lambda: list(map(int, sys.stdin.readline().split()))
inf = float('inf')
mod = 10**9 + 7

k, s = rm()
cnt = 0
for x in range(k, -1, -1):
    for y in range(k, -1, -1):
        if 0 <= s-x-y <= k:
            cnt += 1
print(cnt)
