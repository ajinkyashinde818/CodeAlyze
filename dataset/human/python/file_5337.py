from collections import Counter
N, M = map(int, input().split())
L = [list(map(int, input().split())) for _ in range(M)]

L.sort(key=lambda x: x[0])

ans = []
for i in range(M):
    if (L[i][0] == 1):
        ans.append(L[i][1])

    if (L[i][1] == N):
        ans.append(L[i][0])

c = Counter(ans)
for i, v in c.items():
    if (v >= 2):
        print('POSSIBLE')
        exit()
print('IMPOSSIBLE')
