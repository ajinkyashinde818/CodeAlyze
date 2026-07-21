from collections import defaultdict
N, M = map(int, input().split())
d = defaultdict(list)
for i in range(M):
    a,b = map(int, input().split())
    d[a].append(b)

for j in d[1]:
    if N in d[j]:
        print('POSSIBLE')
        exit()
print('IMPOSSIBLE')
