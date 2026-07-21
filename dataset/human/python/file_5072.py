from collections import defaultdict

N, M = map(int, input().split(' '))
edges = [map(int, input().split(' ')) for _ in range(M)]

paths = defaultdict(set)

for start, end in edges:
    if start == 1:
        paths[end] |= {start, end}
    elif end == N:
        paths[start] |= {start, end}

for path in paths.values():
    if {1, N}.issubset(path):
        print('POSSIBLE')
        break
else:
    print('IMPOSSIBLE')
