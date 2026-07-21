from collections import deque
s = deque(input())
Q = int(input())
c = 0
for _ in range(Q):
  q = input()
  if (q[0] == "1"):
    c += 1
  else:
    if (q[2] == "1"):
      if (c % 2 == 0):
        s.appendleft(q[4])
      else:
        s.append(q[4])
    else:
      if (c % 2 == 0):
        s.append(q[4])
      else:
        s.appendleft(q[4])
if (c % 2 == 0):
  print("".join(list(s)))
else:
  print("".join(list(s))[::-1])
