import sys
sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))
def resolve():
    N, K = lr()
    A = lr()
    vis = [-1]*(N+1)
    dis = [0]*(N+1)
    v = 1
    cnt = 0
    while vis[v] == -1:
        dis[cnt] = v
        vis[v] = cnt
        v = A[v-1]
        cnt += 1
    if K <= vis[v]:
        print(dis[K])
    else:
        print(dis[(K-vis[v])%(cnt-vis[v])+vis[v]])
resolve()
