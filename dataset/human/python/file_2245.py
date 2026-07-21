from math import ceil
INF = 10 ** 10

D, G = map(int, input().split())
pairs = [map(int, input().split()) for _ in range(D)]
ps, cs = zip(*pairs)

minimumsolve = INF

for i in range(1 << D):
    solve = 0
    score = 0
    for j in range(D):
        if i & (1 << j):
            solve += ps[j]
            score += ps[j] * 100 * (j+1) + cs[j]
    if score < G:
        for j in range(D-1, -1, -1):
            if not i & (1 << j):
                neededsolve = ceil((G - score) / (100*(j+1)))
                if neededsolve >= ps[j]:
                    solve = INF
                    break
                else:
                    solve += neededsolve
                    break
    minimumsolve = min(minimumsolve, solve)

print(minimumsolve)
