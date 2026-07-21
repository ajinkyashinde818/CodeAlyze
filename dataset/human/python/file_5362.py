from collections import defaultdict

N, M = map(int, input().split())
route = defaultdict(lambda: False)
for i in range(M):
    ai, bi = map(int, input().split())
    route[(ai, bi)] = True

possible = False
for i in range(2, N):
    if route[(1, i)] and route[(i, N)]:
        possible = True
print('POSSIBLE' if possible else 'IMPOSSIBLE')
