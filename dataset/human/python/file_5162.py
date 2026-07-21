from collections import defaultdict
N, M = map(int, input().split())
d = defaultdict(set)
for _ in range(M):
    src, dst = map(int, input().split())
    d[src].add(dst)

ans = False
for x in d[1]:
    if N in d[x]:
        ans = True
        break
print("POSSIBLE" if ans else "IMPOSSIBLE")
