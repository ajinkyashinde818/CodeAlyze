from collections import deque

s = input()
q = int(input())

d = deque(s)
inv = 0

for _ in range(q):
  Q = list(input().split())
  
  if Q[0]=='1':
    inv += 1
  elif Q[0]=='2':
    if Q[1]=='1':
      if inv%2==0:
        d.appendleft(Q[2])
      else:
        d.append(Q[2])
    elif Q[1]=='2':
      if inv%2==0:
        d.append(Q[2])
      else:
        d.appendleft(Q[2])

if inv%2==0:
  print(*d, sep='')
else:
  print(*deque(reversed(d)), sep='')
