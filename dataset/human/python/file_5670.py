s=input()
from collections import deque
s=deque(s)
ans=0
while len((s)):
  if s[0]==s[-1]:
    if len((s))==1:
      s.pop()
      break
    else:
      s.pop()
      s.popleft()
  else:
    if s[0]=="x" and s[-1]!="x":
      s.append("x")
      ans+=1
    elif s[0]!="x" and s[-1]=="x":
      s.appendleft("x")
      ans+=1
    elif s[0]!="x" and s[-1]!="x":
      print(-1)
      exit(0)

print(ans)
