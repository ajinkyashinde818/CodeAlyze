from itertools import permutations
from math import ceil
D, G = map(int, input().split())
prob = [tuple(map(int, input().split())) for _ in range(D)]
perms = [i for i in range(D)]
ans = 10 ** 100
for p in permutations(perms):
    point = 0
    manip = 0
    for i in range(D):
        if point + (p[i] + 1) * 100 * (prob[p[i]][0] - 1) >= G:
            manip += ceil((G - point) / ((p[i] + 1) * 100))
            ans = min(ans, manip)
            break
        else:
            point += (p[i] + 1) * 100 * prob[p[i]][0] + prob[p[i]][1]
            manip += prob[p[i]][0]
            if point >= G:
                ans = min(ans, manip)
                break
print(ans)
