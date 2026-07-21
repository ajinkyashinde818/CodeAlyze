D,G = map(int, input().split())
pc = [list(map(int, input().split())) for _ in range(D)]
full_score = [0]*D

for i in range(D):
    p,c = pc[i]
    full_score[i] = 100 * (i+1) * p + c

ans = 10**10
from itertools import product
for case in product([0, 1], repeat=D):
    count, score = 0, 0
    for i in range(D):
        p, c = pc[i]
        count += p * case[i]
        score += full_score[i] * case[i]
    if 0 in case:
        i = D - 1 - case[::-1].index(0)
        p, c = pc[i]
        for j in range(p):
            if score >= G:
                break
            score += 100 * (i+1)
            count += 1
    if score >= G:
        ans = min(ans, count)

print(ans)
