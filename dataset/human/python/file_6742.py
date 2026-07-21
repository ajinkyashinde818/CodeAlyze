from collections import deque
S = str(input())
Q = int(input())
d = deque()
reverse = 1
for i in S:
    d.append(i)
for j in range(Q):
  Query = input().split()
  if len(Query) == 1:
    reverse *= -1
  else:
    F = int(Query[1])
    C = str(Query[2])
    if reverse == 1:
      if F == 1:
        d.appendleft(C)
      elif F == 2:
        d.append(C)
    elif reverse == -1:
      if F == 1:
        d.append(C)
      elif F == 2:
        d.appendleft(C)
if reverse == -1:
    d.reverse()
ans = ''.join(d)
print(ans)
