from itertools import product
from math import ceil

d ,g = map(int, input().split())
problem = [0]*d
bonus = [0]*d
compscore = [0]*d
for i in range(d):
    problem[i], bonus[i] = map(int, input().split())
    compscore[i] = 100*(i+1)*problem[i] + bonus[i]
ans = 1001

#product(range(2), repeat=d)の元は、d次元の元であって
#各成分が0or1となるもの(全部で2^d通り）
for c in product(range(2), repeat=d):
    score = 0
    solved = 0
    max_of_notcomp = -1

    for i in range(d):
        if c[i] == 1:
            score += compscore[i]
            solved += problem[i]
        else:
            max_of_notcomp = i
    
    if score < g and score + 100*(max_of_notcomp+1)*(problem[max_of_notcomp]-1) >= g:
        solved += ceil((g - score)/(100*(max_of_notcomp+1)))
        score += ceil((g - score)/(100*(max_of_notcomp+1)))*100*(max_of_notcomp+1)

    if score >= g:
        ans = min(ans, solved)
print(ans)
