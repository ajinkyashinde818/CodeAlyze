import sys
sys.setrecursionlimit(10 ** 6)


def dfs(v, s):
    global origin, cycle
    path[v] = s
    nv = A[v]
    if path[nv] >= 0:
        origin = nv
        cycle = (s + 1) - path[nv]
    else:
        dfs(nv, s + 1)


N, K = map(int, input().split())
A = list(map(lambda x: int(x) - 1, input().split()))
origin = 0
cycle = 0
path = [-1] * N
dfs(0, 0)

if K <= path[origin]:
    for i, s in enumerate(path):
        if s == K:
            print(i + 1)
            break
else:
    rest = K - path[origin]
    rest %= cycle
    for i, s in enumerate(path):
        if s == path[origin] + rest:
            print(i + 1)
            break
