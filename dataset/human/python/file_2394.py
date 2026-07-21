import math
import itertools

(d, g) = map(int, input().split(" "))

p = []
c = []

for i in range(d):
    (_p, _c) = map(int, input().split(" "))
    p.append(_p)
    c.append(_c)

ans = 114514
for order in itertools.permutations(range(d)):
    point = 0
    cnt = 0
    for i in order:
        if g - point <= 100 * (i + 1) * p[i]:
            cnt += math.ceil((g - point) / (100 * (i + 1)))
            break
        elif g - point <= 100 * (i + 1) * p[i] + c[i]:
            cnt += p[i]
            break
        else:
            point += 100 * (i + 1) * p[i] + c[i]
            cnt += p[i]         

    ans = min([ans, cnt])

print(ans)
