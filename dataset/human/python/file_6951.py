from collections import deque
s = input()
q = int(input())
d = deque()
for i in s:
  d.append(i)
rv = 0
lst = [1, 0]
for i in range(q):
  z = input()
  if z[0] == '1':
    rv = lst[rv]
  elif z[2] == '1':
    if rv == 1:
      d.append(z[4])
    else:
      d.appendleft(z[4])
  else:
    if rv == 0:
      d.append(z[4])
    else:
      d.appendleft(z[4])
if rv == 1:
  print(''.join(d)[::-1])
else:
  print(''.join(d))
