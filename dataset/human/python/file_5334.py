from collections import defaultdict
N, M = map(int, input().split())
ab = defaultdict(list)
for i in range(M):
    a, b = map(int, input().split())
    ab[a].append(b)
    ab[b].append(a)

ans = "IMPOSSIBLE"
for u in ab[1]:
    if N in ab[u]:
        ans = "POSSIBLE"
        break
print(ans)
