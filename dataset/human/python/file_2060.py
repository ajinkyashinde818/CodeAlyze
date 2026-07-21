from collections import defaultdict
INF = 10**9+7

n = int(input())
s = str(input())
d = defaultdict(int)
ans = 0
for i in s:
    d[i]+=1
    t = 1
    for ch, cn in d.items():
        if ch ==i:
            continue
        t *= cn +1
    ans = (ans+t)%INF
print(ans)
