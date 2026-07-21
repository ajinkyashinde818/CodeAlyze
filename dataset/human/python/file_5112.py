from collections import defaultdict

N, M = map(int, input().split())

connections = defaultdict(list)
for i in range(M):
    a, b = map(int, input().split())

    connections[a].append(b)
    connections[b].append(a)

for v in connections[1]:
    if N in connections[v]:
        print('POSSIBLE')
        exit()

print('IMPOSSIBLE')
