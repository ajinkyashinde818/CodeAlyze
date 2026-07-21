s=input()
q=int(input())
m=0
from collections import deque
s=deque(s)
for i in range(q):
  l=list(map(str,input().split()))
  if l[0]=="1":
    m+=1
    m%=2
  else:
    if m==0:
      if l[1]=="1":
        s.appendleft(l[2])
      else:
        s.append(l[2])
    else:
      if l[1]=="1":
        s.append(l[2])
      else:
        s.appendleft(l[2])
s=list(s)
if m==1:
  s=s[::-1]
print("".join(s))
