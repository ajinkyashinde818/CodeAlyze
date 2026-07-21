from operator import mul
from functools import reduce

def cmb(n,r):
    r = min(n-r,r)
    if r == 0: return 1
    over = reduce(mul, range(n, n - r, -1))
    under = reduce(mul, range(1,r + 1))
    return over // under

k,s=map(int,input().split())
if s<=k:
    print(cmb(s+2,2))
elif s>2*k:
    print(cmb(3*k-s+2,2))
else:
    ans=0
    for i in range(k+1):
        if s-i>=k:
            ans+=2*k-s+1+i
        else:
            ans+=s+1-i
    print(ans)
