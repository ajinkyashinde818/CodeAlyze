d,g = map(int,input().split())
 
p = []
 
for i in range(d):
    p.append(list(map(int,input().split())))

from itertools import product
from math import ceil
 
ans = 1e09
 
for c in product([0,1],repeat=d):
    score = 0
    num = 0
    ind = 0
    for i in range(d):
        if c[i] == 1:
            score += p[i][0]*100*(i+1) + p[i][1]
            num += p[i][0]
        else:
            ind = max(i,ind)
    
    if g - score <= 0:
        ans = min(ans,num)
    elif g - score <= (p[ind][0]-1)*100*(ind+1):
        num += ceil((g-score)/(100*(ind+1)))
        ans = min(ans,num)
print(ans)
