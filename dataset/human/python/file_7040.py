from collections import deque
s=deque(input())
q=int(input())
direction=1
for i in range(q):
  k=deque(input().split())
  if k[0]=='1':
    direction*=(-1)
  if k[0]=='2':
    if k[1]=='1':
      if direction==1:
        s.appendleft(k[2])
      else:
        s.append(k[2])
    if k[1]=='2':
      if direction==1:
        s.append(k[2])
      else:
        s.appendleft(k[2])
if direction==-1:
  s.reverse()
print("".join(list(s)))
