from math import ceil

D, G = map(int, input().split())
ps, cs = [], []
for _ in range(D):
    p, c = map(int, input().split())
    ps.append(p)
    cs.append(c)

ans = 1000
for pat in range(2 ** D):
    score = 0
    num = 0
    for i in range(D):
        if pat & (1 << i):
            score += 100 * (i + 1) * ps[i] + cs[i]
            num += ps[i]
        else:
            iRest = i

    if score < G:
        n = ceil((G - score) / (100 * (iRest + 1)))
        if n >= ps[iRest]: continue
        num += n

    ans = min(ans, num)

print(ans)
