from collections import defaultdict
N ,M = list(map(int,input().split(" ")))
di = defaultdict(lambda :[])
for _ in range(M):
    a,b = list(map(int,input().split(" ")))
    di[a].append(b)
    di[b].append(a)
ans = "IMPOSSIBLE"
for v in di.values():
    if 1 in v and N in v:
        ans = "POSSIBLE"
        break
print(ans)
