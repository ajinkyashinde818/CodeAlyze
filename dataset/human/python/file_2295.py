import math

d, g = map(int, input().split())
pc = [list(map(int, input().split())) for _ in range(d)]

ans = float("inf")
for i in range(1 << d):
    score = 0
    took = 0
    not_took = []
    for j in range(d):
        p, c = pc[j]
        if i & 1 << j:
            score += (j + 1) * 100 * p + c
            took += p
        else:
            not_took.append(j)
    if score >= g:
        ans = min(ans, took)
    elif len(not_took) != 0:
        last = not_took[-1]
        need = math.ceil((g - score) / ((last + 1) * 100))
        if need <= pc[last][0]:
            ans = min(ans, took+need)
print(ans)
