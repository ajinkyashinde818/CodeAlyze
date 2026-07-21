import sys
import collections
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())
nsl = lambda: map(str, sys.stdin.readline().split())

n = ni()
a = nl()
summ = sum(a) - a[0]
sunn = a[0]
minn = abs(summ - sunn)
for i in range(1, n - 1):
    summ -= a[i]
    sunn += a[i]
    minn = min(minn, abs(summ - sunn))
print(minn)
