from collections import deque

s = deque()
s.extend(list(input()))
q = int(input())

reverse_status = False

for i in range(q):
  query = list(map(format, input().split()))
  if int(query[0]) == 1:
    if reverse_status:
      reverse_status = False
    else:
      reverse_status = True
  else:
    if int(query[1]) == 1:
      if reverse_status:
        s.append(query[2])
      else:
        s.appendleft(query[2])
    else:
      if reverse_status:
        s.appendleft(query[2])
      else:
        s.append(query[2])

if reverse_status:
  s.reverse()
print(''.join(s))
