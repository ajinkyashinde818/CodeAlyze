import itertools
import math

d,g = map(int, input().split())
pc = [list(map(int, input().split())) for i in range(d)]

a = [i for i in range(d)]

b = itertools.permutations(a,d)

ans = float('inf')

for x in b:
    c = 0
    e = 0
    flag = False
    for i in x:
        if e+100*(i+1)*pc[i][0]<=g:
            c += pc[i][0]
            e+=100*(i+1)*pc[i][0]+pc[i][1]
            if e >= g:
                break
        else:
            c += math.ceil((g-e)/(100*(i+1)))
            break
    ans = min(ans, c)

print(ans)
