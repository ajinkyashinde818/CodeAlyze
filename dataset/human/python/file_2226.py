import math

d, g = map(int, input().split())

P = list()
C = list()

for _ in range(d):
    p, c = map(int, input().split())
    P.append(p)
    C.append(c)

check = float('inf')
for i in range(2 ** d):
    ans = 0
    cnt = 0
    for j in range(d):
        # flagがたっていたら
        if (i >> j) & 1:
            ans += P[j] * (j + 1) * 100 + C[j]
            cnt += P[j]
            if ans >= g:
                check = min(check, cnt)
                break
        else:
            rest = j
    extra = P[rest] * (rest + 1) * 100
    if ans < g < (ans + extra):
        cnt += math.ceil(((g - ans) / ((rest + 1) * 100)))
        check = min(check, cnt)

print(check)
