from math import floor,ceil,sqrt
import fractions
from collections import deque
import itertools
from collections import deque
import heapq
N=int(input())
l=[]
pf={}
m=N
for i in range(2,int(m**0.5)+1):
    while m%i==0:
        pf[i]=pf.get(i,0)+1
        m//=i
if m>1:pf[m]=1
#print(pf)
keys=list(pf.keys())
values=list(pf.values())
for i in range(len(keys)):
    l.append([keys[i],values[i]])
#print(l)	#これでlistになった
num=[i*(i+1)//2 for i in range(40)]
#print(num)
ans=0
for i in range(len(l)):
    for j in range(39):
        if num[j]<=l[i][1]<num[j+1]:
            ans=ans+j
print(ans)
