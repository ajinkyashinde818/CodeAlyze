import math
from collections import defaultdict
ml=lambda:map(int,input().split())
ll=lambda:list(map(int,input().split()))
ii=lambda:int(input())
ip=lambda:(input())

"""========main code==============="""
t=ii()
a=ll()
b=ll()
c=ll()
ans=0
for i in range(t):
    ans+=b[a[i]-1]
    if(i<t-1):
        if(a[i]+1==a[i+1]):
            ans+=c[a[i]-1]
print(ans)
