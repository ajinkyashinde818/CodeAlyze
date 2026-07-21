import sys
n, m = map(int, input().split())
paths = {i: [] for i in range(n)}
for _ in range(m):
    a, b = map(int, input().split())
    paths[a - 1].append(b - 1)
for i in paths[0]:
    if n - 1 in paths[i]:
        print('POSSIBLE')
        sys.exit()
print('IMPOSSIBLE')
