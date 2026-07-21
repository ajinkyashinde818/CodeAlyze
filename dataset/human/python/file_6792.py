from collections import deque
S=deque(input())
Q=int(input())
T=[]
m=0
for i in range(Q):
  T.append(input().split())
for i in range(Q):
  if T[i][0]=="1":
    if len(S)>1:
      if m==0:
        m=1
      else:
        m=0
        
  else:
    if T[i][1]=="1":
      if m==0:
        S.appendleft(T[i][2])
      else:
        S.append(T[i][2])
   
    else:
      if m==0:
        S.append(T[i][2])
      else:
        S.appendleft(T[i][2])
if m==0:
  print("".join(S))
else:
  S.reverse()
  print("".join(S))
