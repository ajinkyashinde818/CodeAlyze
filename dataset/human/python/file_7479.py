from collections import deque
s=deque(input().split())
f=False
for i in range(int(input())):
  _=input().split()
  if _[0]=='1':
    f=not f
  else:
    if f:
      [s.append(_[2]) if _[1]=='1'
       else s.appendleft(_[2])]
    else:
      [s.appendleft(_[2]) if _[1]=='1'
       else s.append(_[2])]
print("".join(s)[::-1] if f else "".join(s))
