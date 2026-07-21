import sys,math
sys.setrecursionlimit(10**9)
from collections import defaultdict
 
IA = lambda: map(int,input().split())
IAS= lambda: map(str,input().split())


L, n=IA()
a=list(IA())
a.sort()
cha=[0 for i in range(n)]

cha[0]=a[0]+L-a[n-1]

summ=cha[0]
maxx=cha[0]

for i in range(1,n):
    cha[i]=a[i]-a[i-1]
    summ+=cha[i]
    maxx=max(cha[i],maxx)

print(summ-maxx)
