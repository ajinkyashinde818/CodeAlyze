import sys
from collections import defaultdict
from heapq import heapify, heappush
n,m=map(int,input().split())
s=[tuple(map(int,input().split())) for _ in range(m)]
def hl():
  ret=[]
  heapify(ret)
  return ret
d=defaultdict(hl)
for x in s:
  heappush(d[x[0]],-x[1])
  heappush(d[x[1]],-x[0])
for e in d[1]:
  if d[-e][0]==-n:
    print('POSSIBLE')
    sys.exit()
print('IMPOSSIBLE')
