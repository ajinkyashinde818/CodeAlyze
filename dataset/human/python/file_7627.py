from collections import deque
import sys

S = input()
Q = int(input())
t = deque(S)
rev = False

for _ in range(Q):
  Query = input().split()
  if Query[0] == '1':
    rev = not rev
    
  else:
    F = Query[1]
    C = Query[2]
    if F == '1':
      if rev:
        t.append(C)
      else:
        t.appendleft(C)
    else:
      if rev:
        t.appendleft(C)
      else:
        t.append(C)

result = ''.join(t) 
if rev:
  print(result[::-1])
else:
  print(result)
