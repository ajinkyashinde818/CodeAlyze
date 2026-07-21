import math
import collections
from operator import mul
from functools import reduce
import bisect
import string
import copy


d,g=map(int,input().split())
p=[0]*d
c=[0]*d
for i in range(d):
    p[i],c[i]=map(int,input().split())

y=1000000000000000
for i in range(2**d):
    yi=0
    pi=copy.copy(p)
    gi=copy.copy(g)
    for j in range(d):
        if (i >> j) & 1:
            gi-=c[j]
            gi-=pi[j]*100*(j+1)
            yi+=pi[j]
            pi[j]=0
    ind=copy.copy(d-1)
    while gi>0 and ind>=0:
        if pi[ind]>=2:
            gi-=100*(ind+1)
            yi+=1
            pi[ind]-=1
        else: 
            ind-=1

    if gi<=0 :
        y=min(y,yi)

print(y)
