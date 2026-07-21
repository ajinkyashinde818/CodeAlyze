import sys
input = sys.stdin.readline
N, M = map(int, input().split())
G = [[] for _ in [0]*N]
for _ in [0]*M:
    a, b = map(int, input().split())
    a -= 1; b -= 1
    G[a].append(b)
    G[b].append(a)

for v in G[0]:
    if N-1 in G[v]:
        print('POSSIBLE')
        break
else:
    print('IMPOSSIBLE')
