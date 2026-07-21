from heapq import *
import sys
from collections import *

from itertools import *
from decimal import *
import copy
from bisect import *
import time

import math

def gcd(a,b):
    if(a%b==0):return(b)
    return (gcd(b,a%b))
sys.setrecursionlimit(10**7)
input=lambda :sys.stdin.readline().rstrip()
D,G=map(int,input().split())
PC=[list(map(int,input().split())) for i in range(D)]
value=10**18
for i in range(2**D):
    count=0
    score=G
    bit=[i>>m&1 for m in range(D)]
    for d in range(D):
        p,c=PC[d]
        if bit[d]:
            count+=p
            score-=c+p*(d+1)*100
    for d in range(D)[::-1]:
        p,c=PC[d]
        if not bit[d] and score>0:
            _p=min(p,score//((d+1)*100)+bool(score%((d+1)*100))*1)
            count+=_p
            score-=c+_p*(d+1)*100
    value=min(value,count)
print(value)
