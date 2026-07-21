import sys
import itertools
sys.setrecursionlimit(1000000000)
from heapq import heapify,heappop,heappush,heappushpop

import collections

s = list(input())
s.sort()
ans = ""
for i in range(len(s)):
    ans += s[i]
if ans == "abc":
    print("Yes")
else:
    print("No")
