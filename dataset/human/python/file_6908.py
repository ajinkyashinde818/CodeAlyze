from collections import deque
S = deque(input())
Q = int(input())
rev = False
for i in range(Q):
  q = input()
  if len(q) == 1:
    rev = False if rev else True
  else:
    q, f, c = q.split()
    if rev:
      if f == "1":
        S.append(c)
      else:
        S.appendleft(c)
    else:
      if f == "1":
        S.appendleft(c)
      else:
        S.append(c)
print("".join(reversed(S)) if rev else "".join(S))
