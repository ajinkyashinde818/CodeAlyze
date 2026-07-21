import sys
stdin = sys.stdin
mod = 10**9 + 7

import numpy as np

ns = lambda: stdin.readline().rstrip()
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
sa = lambda h: [list(map(int, stdin.readline().split())) for i in range(h)]

n = ni()
a = na()
b = na()
c = na()
ans = sum(b)
d = np.array(a[:-1]) - np.array(a[1:])
for di, num in enumerate(d):
        if num == -1:
                ans += c[a[di]-1]
print(ans)
