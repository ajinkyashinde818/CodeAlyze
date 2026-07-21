from heapq import *
import sys
from collections import *
from itertools import *
from decimal import *
import copy
from bisect import *
import math
sys.setrecursionlimit(4100000)
def gcd(a,b):
    if(a%b==0):return(b)
    return (gcd(b,a%b))
input=lambda :sys.stdin.readline().rstrip()
N=int(input())
#N=10**18

lst=defaultdict(int)

for i in list(range(2,int(N**.5)+100)):
    while N>1 and N%i==0:
        N//=i
        lst[i]+=1
c=0
if N!=1:
    lst[N]+=1
#print(lst)
for s in lst:
    l=lst[s]
    i=1
    while l>=i:
        l-=i
        c+=1
        i+=1
print(c)
