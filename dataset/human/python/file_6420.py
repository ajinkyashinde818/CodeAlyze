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
if n%2==1:
    print(0)
    exit()
ans=0
i=0
m=10
while n>=m:
    ans+=n//m
    i+=1
    m*=5
print(ans)
