import sys
from collections import deque


N, M = map(int, input().split())
edge = [[] for _ in range(N)]
for s in sys.stdin.readlines():
    a, b = map(int, s.split())
    a -= 1; b -= 1
    edge[a].append(b)
    edge[b].append(a)

path = [float('inf')] * N
q = deque()
q.append((0, 0))
path[0] = 0
while q:
    p, step = q.popleft()
    for np in edge[p]:
        nstep = step + 1
        if path[np] > nstep and nstep <= 2:
            q.append((np, nstep))
            path[np] = nstep

ans = 'POSSIBLE' if path[N - 1] == 2 else 'IMPOSSIBLE'
print(ans)
