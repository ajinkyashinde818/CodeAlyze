s = list(input())
q = int(input())

from collections import deque
d = deque(s)

r = 1

for i in range(q):
  inp = input().split()
  if len(inp)==1:
    r = r*-1
  else:
    f = int(inp[1])
    if f==1:
      f=1
    else:
      f=-1
    if f*r==1:
      d.appendleft(inp[2])
    else:
      d.append(inp[2])
    #print(r,f, d)

if r==1:
  for i in range(len(d)):
    print(d.popleft(), end='')
else:
  for i in range(len(d)):
    print(d.pop(), end='')
