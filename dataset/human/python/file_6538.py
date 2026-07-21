S=input()
Q=int(input())
import sys
from collections import deque
d=deque()
for _ in S:
  d.append(_)
flag=False

for _ in range(Q):
  s = list(sys.stdin.readline())
  if s[0]=="1":
    if flag:
      flag=False
    else:
      flag=True
  else:
    if s[2]=="1":
      if flag:
        d.append(s[4])
      else:
        d.appendleft(s[4])
    else:
      if flag:
        d.appendleft(s[4])
      else:
        d.append(s[4])
      
if flag:
  d.reverse()
  
print("".join(d))
