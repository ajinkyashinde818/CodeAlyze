import sys
import math
import itertools
import collections
import heapq
import re
import numpy as np

rr = lambda: sys.stdin.buffer.readline().rstrip()
rs = lambda: sys.stdin.buffer.readline().split()
ri = lambda: int(sys.stdin.buffer.readline())
rm = lambda: map(int, sys.stdin.buffer.readline().split())
rl = lambda: list(map(int, sys.stdin.buffer.readline().split()))

n = ri()
ans = 0
d = 2
while d**2 <= n:
    if n % d != 0:
        d += 1
        continue
    dd = d
    while n % d == 0:
        n //= d
        d *= dd
        ans += 1
    while n % dd == 0:
        n //= dd
    d = dd + 1
    
if n != 1:
    ans += 1
print(ans)
