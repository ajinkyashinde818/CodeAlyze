d,g=map(int,input().split())
L=[]

for i in range(d):
    L.append([int(i) for i in input().split()])

C=[L[i][0]*(i+1)*100 for i in range(d)]

import itertools
itr=list(itertools.product([0,1],repeat=d))

def calc(key,g):
    cnt=0
    sco=0
    for i in range(d):
        if key[i]==1:
            cnt+=L[i][0]
            sco+=L[i][0]*(i+1)*100+L[i][1]
    rem=g-sco
    #print(rem)
    if rem<=0:
        return cnt
    for i in range(d-1,-1,-1):
        if key[i]==0:
            if rem-L[i][0]*(i+1)*100<=0:
                return cnt+((rem-1)//((i+1)*100))+1
            else:
                rem-=L[i][0]*(i+1)*100
                cnt+=L[i][0]
    return 10**7

ans=10**7
for key in itr:
    #print(key,calc(key,g),ans)
    ans=min(calc(key,g),ans)
print(ans)
