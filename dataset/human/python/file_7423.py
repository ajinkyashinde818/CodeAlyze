from collections import deque
s=list(input())
s=deque(s)
q=int(input())
a=0
for i in range(q):
  A=list(input().split())
  if A[0]=="1":
    a=(a+1)%2
  else:
    if A[1]=="1":
      if a==0:
        s.appendleft(A[2])
      else:
        s.append(A[2])
    else:
      if a==0:
        s.append(A[2])
      else:
        s.appendleft(A[2])
if a==1:
  S=[]
  c=len(s)
  for i in range(c):
    S.append(s[-1])
    s.pop()
else:
  S=s
for i in range(len(S)):
  print(S[i],end="")
print()
