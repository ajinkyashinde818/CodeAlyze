from collections import deque

S = input()
D = deque(S)
C = deque(S)
Q = int(input())

conr = 0

for i in range(Q):
  q = list(input().split())
  if q[0] == "1":
    conr += 1
  else:
    s = q[-1]
    f = int(q[1])
    if conr % 2 == 0:
      if f == 1:
        D.appendleft(s)
      else:
        D.append(s)
    else:
      if f == 1:
        D.append(s)
      else:
        D.appendleft(s)

D = list(D)
if conr % 2 == 1:
  D = D[::-1]
ans = "".join(D)
print(ans)
