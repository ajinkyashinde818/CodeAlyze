from collections import deque
import sys
s = deque(list(input()))
Q = int(input())
cnt = 0

for i in range(Q):
  q = list(input().split())
  if q[0] == '1':
    cnt = (cnt+1) % 2
  elif q[1] == '1':
    if cnt == 0:
      s.appendleft(q[2])
    else:
      s.append(q[2])
  else:
    if cnt == 0:
      s.append(q[2])
    else:
      s.appendleft(q[2])

if cnt == 1:
  s.reverse()
print("".join(s))
