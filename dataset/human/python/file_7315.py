from collections import deque

S = input()
Q = int(input())

q = deque()
rev = 0

for s in S:
  q.append(s)

for _ in range(Q):
  TFC = input()
  if len(TFC) == 1: # T == 1
    rev ^= 1
  else:
    T, F, C = (i for i in TFC.split())  
    if (F == '2' and not rev) or (F == '1' and rev):
      q.append(C)
    else:
      q.appendleft(C)
      
ans = ''.join(q)

if rev:
  print(ans[::-1])
else:
  print(ans)
