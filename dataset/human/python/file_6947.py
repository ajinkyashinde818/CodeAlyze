from collections import deque

s = deque(input())
n = int(input())

point = 0
for i in range(n):
  q = input().split()
  if q.pop(0)=='1':
    point = (point+1)%2
  else:
    _q = int(q.pop(0))-1
    if (point+_q)%2 == 0:
      s.appendleft(q.pop(0))
    else:
      s.append(q.pop(0))

if point == 1:
  s.reverse()

print(''.join(s))
