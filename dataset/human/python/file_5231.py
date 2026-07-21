def check():
    N, M = map(int, input().split())
    edge = [[] for _ in range(N)]
    for i in range(M):
        a,b = map(int, input().split())
        edge[a-1].append(b-1)
        edge[b-1].append(a-1)
    for v in edge[0]:
        if N-1 in edge[v]:
            return 'POSSIBLE'
    return 'IMPOSSIBLE'
print(check())
