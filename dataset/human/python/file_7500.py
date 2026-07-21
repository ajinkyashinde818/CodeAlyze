from collections import deque
import sys
input = sys.stdin.readline
s = deque(input().rstrip())
q = int(input())
flg = 0
for _ in range(q):
  t = input()
  if t[0] == "1":
    flg = 1-flg
  else:
    _,x,y = t.split()
    if x == "1":
      if flg:
        s.append(y)
      else:
        s.appendleft(y)
    else:
      if flg:
        s.appendleft(y)
      else:
        s.append(y)
if flg:
  u = list(s)[::-1]
  print(*u,sep="")
else:
  print(*s,sep="")
