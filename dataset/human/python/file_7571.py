from collections import deque
S=list(input())
Q=int(input())
ls=[list(input().split()) for _ in range(Q)]
D=deque()
for i in range(len(S)):
  D.append(S[i])  
a=1
for i in range(Q):
  if ls[i][0]=="1":
    a*=(-1)
  else:
    if (ls[i][1]=="1" and a==1) or (ls[i][1]=="2" and a==-1):
      D.appendleft(ls[i][2])
    else:
      D.append(ls[i][2])
if a==1:
  while D:
    print(D.popleft(), end="")
else:    
  while D:
    print(D.pop(), end="")
