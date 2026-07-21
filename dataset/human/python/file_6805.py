from collections import deque
s = list(input())
d = deque(s)
q = int(input())
flag = True
for i in range(q):
  l = list(map(str,input().split()))
  if l[0] == '1':
    if flag:
      flag = False
    else:
      flag = True
  else:
    if l[1] == '1':
      if flag:
        d.appendleft(l[2])
      else:
        d.append(l[2])
    else:
      if flag:
        d.append(l[2])
      else:
        d.appendleft(l[2])
if flag:
  print(''.join(d))
else:
  d.reverse()
  print(''.join(d))
