import sys
import heapq
import math
import fractions
import bisect
import itertools
from collections import Counter
from collections import deque
from operator import itemgetter
def input(): return sys.stdin.readline().strip()
def mp(): return map(int,input().split())
def lmp(): return list(map(int,input().split()))

n=int(input())
a=lmp()
b=lmp()
c=lmp()
ans=b[a[0]-1]
for i in range(1,n):
    ans+=b[a[i]-1]
    if a[i]-a[i-1]==1:
        ans+=c[a[i]-2]
print(ans)
