import collections

s = collections.deque(input())
q = int(input())
rev = 0
for i in range(q):
  tmp = input().split()
  if len(tmp) == 1:
    rev += 1
  else:
    if tmp[1] == '1':
      if rev % 2 == 0:
        s.appendleft(tmp[2])
      else:
        s.append(tmp[2])
    else:
      if rev % 2 == 0:
        s.append(tmp[2])
      else:
        s.appendleft(tmp[2])
if rev % 2:
  while True:
    try:
      print(s.pop(), end='')
    except IndexError:
      break
else:
  while True:
    try:
      print(s.popleft(), end='')
    except IndexError:
      break
