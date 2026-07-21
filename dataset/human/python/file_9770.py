import sys
sys.setrecursionlimit(10**6)

N, K = map(int, input().split())
*A, = map(int, input().split())
A = [a-1 for a in A]

path = []
visited = {}


def dfs(v, k):
    if v in visited:
        return v

    visited[v] = k
    path.append(v)
    return dfs(A[v], k+1)


origin = dfs(0, 0)
i = visited[origin]
loop = path[i:]


if K <= i:
    print(path[K] + 1)
else:
    j = (K - i) % len(loop)
    print(loop[j] + 1)
