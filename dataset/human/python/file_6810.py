from collections import deque
S=deque(list(input()))
Q=int(input())
rev=1

for _ in range(Q):
  q=input().split()
  if q[0]=="1":
    rev*=-1
  else:
    F,C=int(q[1]),q[2]
    if F==1:
      if rev==1:
        S.appendleft(C)
      else:
        S.append(C)
    else:
      if rev==1:
        S.append(C)
      else:
        S.appendleft(C)

if rev==-1:
  S.reverse()
print("".join(list(S)))
