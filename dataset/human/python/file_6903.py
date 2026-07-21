from collections import deque
s=deque(list(input()))
q=int(input())
rev=0
for i in range(q):
  t=list(input().split(" "))
  if t[0]=="1":
    rev=rev+1
  else:
    if t[1]=="1":
      if rev%2==0:
        s.appendleft(t[2])
      else:
        s.append(t[2])
    else:
      if rev%2==0:
        s.append(t[2])
      else:
        s.appendleft(t[2])
if rev%2==0:
  print("".join(s))
else:
  s.reverse()
  print("".join(s))
