from collections import deque
import sys

N, M = map(int, input().split())

G = [deque([]) for i in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)

time = 0

for i in range(len(G[0])):
    if (N-1) in G[G[0][i]]:
        print('POSSIBLE')
        sys.exit()

print('IMPOSSIBLE')
