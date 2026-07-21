from collections import defaultdict
N, M = map(int, input().split())
route = defaultdict(int)
for _ in range(M):
    a, b = map(int, input().split())
    route[a, b] = 1
for i in range(2, N):
    if route[1, i] == route[i, N] == 1:
        print('POSSIBLE')
        exit()
print('IMPOSSIBLE')
