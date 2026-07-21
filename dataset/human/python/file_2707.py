from itertools import product
import math
D,G = map(int,input().split())
A = [list(map(int,input().split())) for _ in range(D)]
cmin = 10**4
for x in product((0,1),repeat=D):
    scr = 0
    cnt = 0
    j = -1
    for i in range(D):
        if x[i]==1:
            scr += 100*(i+1)*A[i][0]+A[i][1]
            cnt += A[i][0]
        else:
            j = i
    if scr>=G:
        cmin = min(cmin,cnt)
    else:
        k = math.ceil((G-scr)/(100*(j+1)))
        if k<A[j][0]:
            cmin = min(cmin,cnt+k)
print(cmin)
