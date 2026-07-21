D,G=map(int,input().split())
pc=[list(map(int,input().split())) for i in range(D)]
r=1000
from itertools import product
for X in product(range(2),repeat=D):
    g,a=0,0
    for i,x in enumerate(X):
        if x:
            g+=pc[i][1]+pc[i][0]*(i+1)*100
            a+=pc[i][0]
    for i in range(D-1,-1,-1):
        if X[i]==1:
            continue
        if g>=G:
            break
        n=min(pc[i][0]-1,-((g-G)//((i+1)*100)))
        a+=n
        g+=n*(i+1)*100
    if g>=G:
        r=min(r,a)
print(r)
