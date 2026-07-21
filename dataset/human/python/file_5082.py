import sys
from collections import deque
N, M = map(int, input().split())
G = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    G[a - 1].append(b - 1)
    G[b - 1].append(a - 1)
for g in G[0]:
    if N - 1 in G[g]:
        print('POSSIBLE')
        sys.exit()
print('IMPOSSIBLE')
