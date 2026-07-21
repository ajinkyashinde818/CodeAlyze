D,G = map(int,input().split())
pc = [list(map(int,input().split())) for i in range(D)]
ans = 10**9
from math import ceil
for i in range(2**D):
    now = 0
    score = 0
    for j in range(D):
        if i>>j & 1:
            now += pc[j][0]
            score += pc[j][0]*100*(j+1) + pc[j][1]

    if score >= G:
        ans = min(ans,now)
    else:
        for j in reversed(range(D)):
            if i>>j & 1 == 0:
                if ceil((G-score)/(100*(j+1))) < pc[j][0]:
                    now += ceil((G-score)/(100*(j+1)))
                    break
        else:
            continue

        if now==0:
            continue
        ans = min(ans,now)

print(ans)
