from collections import defaultdict

N, M = map(int, input().split())
E = defaultdict(list)
for _ in range(M):
    a, b = map(int, input().split())
    E[a].append(b)
    E[b].append(a)
for i in range(1, N+1):
    if 1 in E[i] and N in E[i]:
        print('POSSIBLE')
        break
else:
    print('IMPOSSIBLE')
