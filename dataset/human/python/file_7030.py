import sys, math
from collections import deque

S = deque(input())
Q = int(input())

count_reverse = 0
for i in range(Q):
  q = [j for j in input().split()]
  if len(q) == 1:
    count_reverse += 1
  else:
    if q[1] == '1':
      if count_reverse % 2 == 0:
        S.appendleft(q[-1])
      else:
        S.append(q[-1])
    else:
      if count_reverse % 2 == 0:
        S.append(q[-1])
      else:
        S.appendleft(q[-1])
        
ret = ''
if count_reverse % 2:
  for s in list(S)[::-1]:
    ret = ret + s
else:
  for s in S:
    ret = ret + s
    
print(ret)
