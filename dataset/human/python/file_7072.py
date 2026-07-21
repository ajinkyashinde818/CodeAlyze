from collections import deque as dq
s = input()
nq = int(input())

s = dq(s)

jun = True
for i in range(nq):
  query = input().split()
  if query[0] == '1':
    jun = not jun
    continue
  if jun:
    if query[1] == '1':
      s.appendleft(query[2])
    else:
      s.append(query[2])
  else:
    if query[1] == '1':
      s.append(query[2])
    else:
      s.appendleft(query[2])
if jun:
  print(''.join(s))
else:
  print(''.join(list(s)[::-1]))
