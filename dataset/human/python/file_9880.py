import sys
from collections import Counter
from collections import deque
def input(): return sys.stdin.readline().strip()
def mp(): return map(int,input().split())
def lmp(): return list(map(int,input().split()))

n,k=mp()
a=lmp()
l=[]
i=0
ch=[0]*(n+1)
while True:
    if ch[i]==1:
        break
    else:
        ch[i]=1
        l.append(a[i])
        i=a[i]-1


x=l.index(a[i])
y=len(l)-x

if k<=x:
    print(l[k-1])
else:
    print(l[(k-x-1)%y+x])
