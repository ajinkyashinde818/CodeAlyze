d, g = list(map(int, input().split()))
spc = []
for s in range(100, d * 100 + 1, 100):
    p, c = list(map(int, input().split()))
    spc.append([s, p, c + s * p])

from itertools import product
ans = float('inf')
for comps in product(range(2), repeat=d):
    cnt = sum(p * x for (s, p, c), x in zip(spc, comps))
    scr = sum(c * x for (s, p, c), x in zip(spc, comps))
    if scr >= g:
        if cnt < ans:
            ans = cnt
        continue
    for (s, p, c), x in zip(spc, comps):
        if x or s * (p - 1) + scr < g:
            continue
        cnt += -((scr - g) // s)
        if cnt < ans:
            ans = cnt

print(ans)
