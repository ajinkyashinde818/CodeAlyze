from itertools import product
from math import ceil
D,G = map(int,input().split(" "))
p,c = [0]*D,[0]*D

for i in range(D):
    p[i],c[i] = map(int,input().split(" "))

ans = float('inf')
for pat in range(1<<D):
    point,prob,maxv = 0,0,0
    for b in range(D):
        if (pat >> b) & 1:
            point += ((100*(b+1))*p[b] + c[b])
            prob += p[b]
        else:
            maxv = max(maxv,b+1)

    if point >= G:
        ans = min(ans,prob)

    elif maxv != 0:
        if G <= (point + (maxv*100)*p[maxv-1]):
            ans = min(ans,prob+ceil((G-point)/(maxv*100)))

print(ans)
