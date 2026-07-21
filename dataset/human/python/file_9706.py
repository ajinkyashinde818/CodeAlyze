def n0():return int(input())
def n1():return [int(x) for x in input().split()]
def n2(n):return [int(input()) for _ in range(n)]
def n3(n):return [[int(x) for x in input().split()] for _ in range(n)]

n,k=n1()
a=[0]
a.extend(n1())

from collections import deque
p=deque([1])
nex=1
town=[0]*(n+1)
town[1]=1
for i in range(n+1):
    last=nex
    nex=a[last]
    p.append(nex)
    if town[nex]==1:
        break
    else:
        town[nex]=1
p.pop()
first=p.index(nex)
length=len(p)
if k<length:
    print(p[k])
else:
    print(p[(k-first)%(length-first)+first])
