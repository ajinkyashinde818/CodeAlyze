import sys


sys.setrecursionlimit(10 ** 6)


def dfs(v):
    path.append(v)
    visited[v] = 1
    nv = A[v]
    if visited[nv] == 1:
        return nv
    return dfs(nv)


N, K = map(int, input().split())
A = list(map(lambda x: int(x) - 1, input().split()))
visited = [0] * N
path = []
cycle_start = dfs(0)
cycle_len = len(path) - path.index(cycle_start)
head_len = len(path) - cycle_len
if K <= head_len:
    print(path[K] + 1)
else:
    K -= head_len
    print(path[head_len + K % cycle_len] + 1)
