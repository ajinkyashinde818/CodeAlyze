import math

d, g = map(int, input().split())
p, c = [], []
for i in range(d):
    pi, ci = map(int, input().split())
    p.append(pi)
    c.append(ci)
compl = [100 * (i+1) * p[i] + c[i] for i in range(d)]

ans = 1e9
for i in range(2 ** d):
    score = num = 0
    for j in range(d):
        if (i >> j) & 1:
            score += compl[j] 
            num += p[j] 
        else:
            # index of highest rest valuable p.
            rest_idx = j
    if score < g:
        need = math.ceil((g - score) / (100 * (rest_idx + 1)))
        if need >= p[rest_idx]:
            continue
        num += need
    ans = min(ans, num)
print(ans)
