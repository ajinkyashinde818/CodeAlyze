import sys
import itertools
sys.setrecursionlimit(1000000000)
from heapq import heapify,heappop,heappush,heappushpop
import math
import collections


n,m = map(int,input().split())
edge = [[] for i in range(n)]
for i in range(m):
    a,b = map(int,input().split())
    edge[a-1].append(b-1)
    edge[b-1].append(a-1)
for i in edge[0]:
    if n-1 in edge[i]:
        print("POSSIBLE")
        sys.exit()
print("IMPOSSIBLE")
