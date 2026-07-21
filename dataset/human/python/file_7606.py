import sys
from collections import deque
input = sys.stdin.readline
S=deque(input()[:-1])
Q=int(input())
r = False
for _ in range(Q):
  qs = input()[:-1].split(' ')
  if len(qs) == 1:
    r = not r
  else:
    if (qs[1] == '1' and (not r)) or (qs[1] == '2' and r):
      S.appendleft(qs[2])
    else:
      S.append(qs[2])
if r:
  print(''.join(reversed(S)))
else:
  print(''.join(S))
