import sys

sys.setrecursionlimit(10**7)

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().rstrip()  # ignore trailing spaces

n, k = na()
a = na()
for i in range(n):
    a[i] -= 1
ct = [0 for i in range(n)]
seen = [False] * n
def dfs(v):
    nv = a[v]
    seen[v] = True
    if ct[v] + 1 == k:
        return nv, 0
    elif seen[nv]:
        loop = ct[v] - ct[nv] + 1
        res = (k - ct[v] - 1) % loop
        return nv, res
    else:
        ct[nv] = ct[v] + 1
        return dfs(nv)

nv, res = dfs(0)
for i in range(res):
    nv = a[nv]
print(nv + 1)
