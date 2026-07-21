from collections import deque
s=deque(input())
f=False
for _ in range(int(input())):
  t=list(input().split())
  if t[0]=='1':
    if f is False:
      f = True
    else:
      f = False
  else:
    if t[1]=='1':
      if f is False:
      	s.appendleft(t[2])
      else:
        s.append(t[2])
    else:
      if f is False:
      	s.append(t[2])
      else:
        s.appendleft(t[2])
x=''.join(map(str,s))
if f is False:
	print(x)
else:
  print(x[::-1])
