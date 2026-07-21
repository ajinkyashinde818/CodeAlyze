import math
from decimal import *
import random

def pf(n):
    rn = int(n)
    ans = []
    while(n%2==0):
        if(2 not in ans):
            ans.append(2)
        n//=2
    for i in range(3, int(math.sqrt(rn)), 2):
        while(n%i==0):
            if(i not in ans):
                ans.append(i)
            n//=i
            if(n==1):
                break
        if(n==1):
            break
    if(n>2):
        ans.append(n)
    return sorted(ans)
n = int(input())
d = pf(n)
if(d=={}):
    print(1)
else:
    ans = 0
    for i in range(len(d)):
        cnt = 1
        while(n >= d[i]**cnt):
            if(n%(d[i]**cnt)==0):
                n//=(d[i]**cnt)
                ans+=1
            cnt+=1
    print(ans)
