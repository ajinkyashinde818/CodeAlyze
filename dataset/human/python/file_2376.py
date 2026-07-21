from itertools import product
from math import ceil
d, g = map(int, input().split())
pc = [list(map(int, input().split())) for i in range(d)]

ans = 10**9
for bit in product([0, 1], repeat=d):
    score = 0
    probs = 0
    for i, b in enumerate(bit):
        p, c = pc[i]
        if b==1:
            probs+=p
            score+=100*(i+1)*p
            score+=c
    if score >= g:
        ans = min(ans, probs)
    else:
        # greedyに足す
        for i, b in list(enumerate(bit))[::-1]:
            p, c = pc[i]
            if b==1:
                continue
            if score+100*(i+1)*p >= g:
                a = ceil((g-score)/(100*(i+1)))
                probs += a
                score += (100*(i+1))*a
                if a == p: score += c
                break
            else:
                probs += p
                score += (100*(i+1))*p+c
                if score >= g: break
        if score >= g:
            ans = min(ans, probs)
print(ans)
