import sys,heapq
from collections import deque,defaultdict
printn = lambda x: sys.stdout.write(x)
inn = lambda : int(input())
inl   = lambda: list(map(int, input().split()))
inm   = lambda:      map(int, input().split())
DBG = True # and False
def ddprint(x):
  if DBG:
    print(x)

cnt = 0
r,g,b,n = inm()
for i in range(n//r+2):
  for j in range((n-i*r)//g+2):
      rest = n-i*r-j*g
      if rest >= 0 and rest%b == 0:
          cnt += 1
print(cnt)
