f=input
from collections import deque
s=deque(f())
n=int(f())
t=0
for i in range(n):
  q=f()
  if q[0]=='1': t^=1
  elif int(q[2])+t==2: s.append(q[4])
  else: s.appendleft(q[4])
print(''.join([s,list(s)[::-1]][t]))
