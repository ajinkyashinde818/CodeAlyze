import sys
from collections import Counter
from collections import deque
import heapq
import math
import fractions
import bisect
import itertools
def input(): return sys.stdin.readline().strip()
def mp(): return map(int,input().split())
def lmp(): return list(map(int,input().split()))

n=int(input())
a=lmp()
sa=0
sb=sum(a)
ans=float("inf")
for i in range(n-1):
    sa+=a[i]
    sb-=a[i]
    ans=min(ans,abs(sa-sb))
print(ans)
