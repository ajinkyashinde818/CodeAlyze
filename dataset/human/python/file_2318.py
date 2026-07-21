from math import ceil

D, G = map(int, input().split())
Pd, Cd = [0] * D, [0] * D

for i in range(D):
    Pd[i], Cd[i] = map(int, input().split())


ans = float("inf")
for i in range(1 << D):
    score, solved, unsolved = 0, 0, 0
    for j in range(D):
        if i & (1 << j):
            score += 100 * (j+1) * Pd[j] + Cd[j]
            solved += Pd[j]
        else:
            unsolved = j

    rest = G - score
    if rest > 0:
        k = 100 * (unsolved+1)
        if k * Pd[unsolved] < rest:
            continue
        solved += ceil(rest/k)

    ans = min(ans, solved)

print(ans)
