from collections import deque
s=deque(list(input()))
q=int(input())
REVERSE=False
for _ in range(q):
  Input=input().split()
  if len(Input)==1:
    REVERSE = not REVERSE
  else:
    f=int(Input[1])
    c=Input[2]
    if not REVERSE:
      if f==1:
        s.appendleft(c)
      else:
        s.append(c)
    else:
      if f==1:
        s.append(c)
      else:
        s.appendleft(c)
if not REVERSE:
  print("".join(s))
else:
  print("".join(reversed(s)))
