import math

D, G = map(int, input().split())
P = [list(map(int, input().split())) for _ in range(D)]

ret = 10000
for i in range(1 << D):
    buf = 0
    s = 0
    for k in range(D):
        if i & (1 << k):
            buf += P[k][0]
            s += P[k][0] * (k + 1) * 100 + P[k][1]
    if s < G:
        f = False
        for k in reversed(range(D)):
            if not i & (1 << k):
                t = math.ceil((G - s) / ((k + 1) * 100))
                if t <= P[k][0] - 1:
                    buf += t
                    f = True
                    break
        if not f:
            continue
    ret = min(ret, buf)

print(ret)
