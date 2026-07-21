import sys
stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
nn = lambda: list(stdin.readline().split())
ns = lambda: stdin.readline().rstrip()

n = ni()
a = na()

import numpy as np
a = list(np.cumsum(a))

ans = 100000000000000

for i in range(n-1):
    ans = min(ans, abs(a[-1]-a[i]*2))

print(ans)
