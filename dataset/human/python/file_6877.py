from collections import deque
s = input()
s = deque(s)
n = int(input())
cnt = False
for i in range(n):
  L = input()
  if len(L) == 1:
    cnt  ^=1 
  else:
    a,b,c = L.split()
    if cnt:
      if b == "1":
        s.append(c)
      else:
        s.appendleft(c)
    else:
      if b == "1":
        s.appendleft(c)
      else:
        s.append(c)
if cnt:
    s = reversed(s)
    print("".join(s))
else:
    print("".join(s))
