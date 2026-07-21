from collections import defaultdict
N, M = map(int,input().split())
d = defaultdict(int)
for _ in range(M):
    a, b = map(int,input().split())
    if a == 1:
        d[b] += 1
    if b == N:
        d[a] += 1
if 2 in d.values():
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')
