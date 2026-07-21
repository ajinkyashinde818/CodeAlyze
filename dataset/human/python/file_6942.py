from collections import deque
S = input()
Q = int(input())
F=0
d=deque(S)
for i in range(Q):
  q=list(map(str,input().split()))
  if q[0]=="1":
    F+=1
    F%=2
  else:
    if q[1]=="1":
      if F==0:
        d.appendleft(q[2])
      else:
        d.append(q[2])
    else:
      if F==0:
        d.append(q[2])
      else:
        d.appendleft(q[2])  
d=list(d)
if F%2==0:
  print("".join(d))
else:
  print("".join(d[::-1]))
