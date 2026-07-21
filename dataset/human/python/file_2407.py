D,G=map(int, input().split())

L=[]
for i in range(D):
    p,c=map(int, input().split())
    L.append((p,c))

from itertools import permutations
from math import ceil
ans=float("INF")
for t in permutations(range(1,D+1)):
    #print(t)
    t=list(t)
    now=G
    sub=0
    for x in t:
        p,c=L[x-1]
        if now/(x*100)<=p:
            sub+=ceil(now/(x*100))
            break
        elif x*p*100+c>=now:
            sub+=p
            break
        else:
            now-=x*p*100+c
            sub+=p

    #print(t, sub)
    ans=min(ans, sub)
    
print(ans)
