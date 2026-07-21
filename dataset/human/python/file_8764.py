import copy
from functools import reduce
k,n=map(int,input().split())
a=list(map(int,input().split()))
c=copy.copy(a)
c.insert(0,0)
a.insert(n,(k+a[0]))
b=list(map(lambda a,b:a-b,a,c))
d=reduce(lambda a,b:b if b>a else a,b)
print(k-d)
