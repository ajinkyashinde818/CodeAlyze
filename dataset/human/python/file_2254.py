import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

D, G = na()
p = []
c = []
for i in range(D):
    x, y = na()
    p.append(x)
    c.append(y)

ans = 99999999
for i in range(1<<D):
    ct = 0
    score = 0
    for j in range(D):
        if i>>j&1:
            score += c[j]
            score += p[j] * (j+1) * 100
            ct += p[j]
    for j in range(D-1, -1, -1):
        if i>>j&1: continue
        if score >= G: break
        g = (j+1)*100
        got = (G-score+g-1)//g
        score += min(got, p[j]) * g
        ct += min(got, p[j])
    ans = min(ans, ct)
print(ans)
