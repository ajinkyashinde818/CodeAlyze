import sys
import itertools
sys.setrecursionlimit(1000000000)
from heapq import heapify,heappop,heappush,heappushpop
import math
import collections

n = int(input())
a = list(map(int,input().split()))
d = sum(a)
snuke = 0
arai = 0
ans = 10000000000
for i in range(n-1):
    snuke += a[i]
    arai = d - snuke
    ans = min(ans,abs(snuke-arai))
print(ans)
