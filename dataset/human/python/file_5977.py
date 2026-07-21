mod=10**9+7
import math
import sys
from collections import deque
import heapq
import copy
import itertools
from itertools import permutations
from itertools import combinations
import bisect
def mi() : return map(int,sys.stdin.readline().split())
def ii() : return int(sys.stdin.readline().rstrip())
def i() : return sys.stdin.readline().rstrip()
a=ii()
l=[list(mi()) for _ in range(3)]
ans=0
for i in range(a-1):
  ans+=l[1][l[0][i]-1]
  if l[0][i]+1==l[0][i+1]:
    ans+=l[2][l[0][i]-1]
print(ans+l[1][l[0][a-1]-1])
