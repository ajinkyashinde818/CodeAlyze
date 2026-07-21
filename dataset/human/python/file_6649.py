from collections import deque
s=deque(list(input()))
q=int(input())
l = [list(input().split()) for i in range(q)]
c=0
for i in range(q):
  if l[i][0]=="1":
    c+=1
  elif c%2==0 and l[i][1]=="1":
    s.appendleft(l[i][2])
  elif c%2==0:
    s.append(l[i][2])
  elif c%2==1 and l[i][1]=="1":
    s.append(l[i][2])
  else:
    s.appendleft(l[i][2])
s=list(s)
if c%2==1:
  s=s[::-1]
print(*s, sep="")
