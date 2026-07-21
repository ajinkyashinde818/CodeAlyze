import sys
import collections
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())
nsl = lambda: map(str, sys.stdin.readline().split())

n = ni()
a = nl()
count = 0
for i in range(len(a)):
    if a[i] < 0:
        count += 1
        a[i] = -a[i]
ans = 0
if count % 2 == 0:
    ans = sum(a)
else:
    ans = sum(a) - 2 * min(a)
print(ans)
