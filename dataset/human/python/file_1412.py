import sys
import itertools

rr = lambda: sys.stdin.readline().rstrip()
rs = lambda: sys.stdin.readline().split()
ri = lambda: int(sys.stdin.readline())
rm = lambda: map(int, sys.stdin.readline().split())
rl = lambda: list(map(int, sys.stdin.readline().split()))
inf = float('inf')
mod = 10**9 + 7

n = ri()
a = rl()
s = sum(a)
t = list(itertools.accumulate(a))
min_ = inf
for i in range(n-1):
    x = t[i]
    min_ = min(min_, abs((s-x) - x))
print(min_)
