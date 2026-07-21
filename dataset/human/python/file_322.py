import numpy as np

n=int(input())
a=[int(i) for i in input().split()]
sign=0
ans=0
for i in range(n):
    if a[i]<0:
        a[i]=-1*a[i]
        sign+=1
m=min(a)
if sign%2==1:
    ans=sum(a)-2*m
else:
    ans=sum(a)
print(ans)
