n, m = map(int, input().split())

from collections import defaultdict
d = defaultdict(list)
for _ in range(m):
    a, b = map(int, input().split())
    d[a].append(b)
    d[b].append(a)
    
if len(set(d[1]) & set(d[n])) >= 1:
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')
