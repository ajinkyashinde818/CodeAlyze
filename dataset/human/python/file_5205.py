N,M=map(int, input().split())
from collections import defaultdict
G=defaultdict(lambda: [])
for _ in range(M):
    a,b=map(int, input().split())
    G[a].append(b)
    G[b].append(a)
for nx in G[1]:
    if N in G[nx]:
        print("POSSIBLE")
        exit()
print("IMPOSSIBLE")
