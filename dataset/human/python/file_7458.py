from collections import deque
Q=deque(list(input()))
rev=0

for _ in range(int(input())):
  query=input()
  if query[0]=='1':
    rev^=1
  else:
    q,f,c=query.split()
    if (f=='1')^(rev):
      Q.appendleft(c)
    else:
      Q.append(c)

if rev:
  Q=reversed(Q)
print(''.join(Q))
