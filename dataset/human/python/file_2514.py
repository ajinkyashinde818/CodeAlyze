import itertools
import math
d, g = map(int, input().split())
l = []
cl = []
for i, _ in enumerate(range(d)):
    p, c = map(int, input().split())
    l.append([p, c])
    cl.append(p * 100 * (i + 1) + c)

ans = float("INF")
for flags in itertools.product([0, 1], repeat=d):
    q = []
    cost = g
    cnt = 0
    for i, flag in enumerate(flags):
        if flag:
            cost -= cl[i]
            cnt += l[i][0]
        else:
            q.append(i)

    q.reverse()
    if cost > 0:
        for i in q:
            if math.ceil(cost / (100 * (i + 1))) <= l[i][0]:
                cnt += math.ceil(cost / (100 * (i + 1)))
                break
        else:
            cnt = float("INF")
    ans = min(ans, cnt)
print(ans)
