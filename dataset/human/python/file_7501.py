from collections import deque
S = list(input())
q_num = int(input())
d = deque(S)
rev = True
for _ in range(q_num):
  query = list(input().split())
  if(query[0] == "1"):
    rev = not rev
  if(query[0] == "2"):
    if(rev):
      if(query[1] == "1"):
        d.appendleft(query[2])
      else:
        d.append(query[2])
    else:
      if(query[1] == "1"):
        d.append(query[2])
      else:
        d.appendleft(query[2])
if(rev):
  print("".join(d))
else:
  d.reverse()
  print("".join(d))
