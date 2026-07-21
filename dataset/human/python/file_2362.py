from copy import deepcopy
from math import ceil
d,g=map(int,input().split())
lst=[]
for i in range(1,d+1):
    p,c=map(int,input().split())
    lst.append([i*100,p,c])
ans=1145141919
for p in range(d):
    tmp=deepcopy(lst)
    tmp=tmp[:p]+tmp[p+1:]
    for i in range(2**(d-1)):
        point=0
        problem=0
        for j in range(d-1):
            if (i>>j)&1:
                point+=tmp[j][0]*tmp[j][1]+tmp[j][2]
                problem+=tmp[j][1]
        if point<g:
            extra=g-point
            if extra>lst[p][0]*lst[p][1]+lst[p][2]:
                continue
            if extra>lst[p][0]*lst[p][1]:
                ans=min(ans,problem+lst[p][1])
                continue
            problem+=ceil(extra/lst[p][0])
        ans=min(ans,problem)

print(ans)
