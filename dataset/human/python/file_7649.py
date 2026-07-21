from collections import deque
S=input()
Q=int(input())

d=deque(S)
rev=False
for q in range(Q):
  q=input()
  if q=="1":
    rev=not rev
  else:
    qlist=q.split()
    if qlist[1]=="1":
      if not rev:
        d.appendleft(qlist[2])
      else:
        d.append(qlist[2])
    elif qlist[1]=="2":
      if not rev:
        d.append(qlist[2])
      else:
        d.appendleft(qlist[2])

d2=deque()
if not rev:
  d2=deque(d)
else:
  d2=deque(reversed(d))
  
print("".join(d2))
