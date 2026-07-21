import sys
stdin = sys.stdin
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
nn = lambda: list(stdin.readline().split())
ns = lambda: stdin.readline().rstrip()
sys.setrecursionlimit(10**6)

n,m = na()
g = [[] for i in range(n)]
for i in range(m):
    a,b = na()
    a,b = a-1,b-1
    g[a].append(b)
    g[b].append(a)

for i in g[0]:
    if n-1 in g[i]:
        print('POSSIBLE')
        exit()

print('IMPOSSIBLE')
