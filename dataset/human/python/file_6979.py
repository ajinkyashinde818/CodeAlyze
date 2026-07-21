from collections import deque
S=deque(list(input()))
Q=int(input())
count=0
for i in range(Q):
  A=list(input().split())
  if A[0]=="1":
    count=(count+1)%2
  else:
    if A[1]=="1":
      if count==0:
        S.appendleft(A[2])
      else:
        S.append(A[2])
    else:
      if count==0:
        S.append(A[2])
      else:
        S.appendleft(A[2])
if count==1:
  S.reverse()
ans="".join(S)
print(ans)
