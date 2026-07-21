import sys
import collections
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())
nsl = lambda: map(str, sys.stdin.readline().split())

n, m = nm()
lis = [[] for _ in range(n + 1)]
for i in range(m):
    a, b = nm()
    lis[a].append(b)
    lis[b].append(a)
for i in range(len(lis[1])):
    l = lis[1][i]
    if n in lis[l]:
        print('POSSIBLE')
        exit()
print('IMPOSSIBLE')
