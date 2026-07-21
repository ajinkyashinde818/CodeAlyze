S = input()

from collections import deque
S = deque(S)

Q = int(input())
rev = False

for i in range(Q):
  q = input().split()
  if q[0] == "1":
    rev ^= True
  else:
    F = q[1]
    if (F == "1" and (not rev)) or (F == "2" and rev):
      S.appendleft(q[2])
    else:
      S.append(q[2])

S = "".join(list(S))
if rev:
  S = S[::-1]
  
print(S)
