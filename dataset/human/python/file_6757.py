from collections import deque

s = deque(list(input()))

q = int(input())

reverse = 0

for i in range(q):
  query = list(input().split())
  if query[0] == '1':
    reverse ^= 1
    continue
  else:
    if query[1] == '1':
      if reverse:
        s.append(query[2])
      else:
        s.appendleft(query[2])
    else:
      if reverse:
        s.appendleft(query[2])
      else:
        s.append(query[2])
if reverse:
  print(''.join(s)[::-1])
else:
  print(''.join(s))
