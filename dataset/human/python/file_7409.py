from collections import deque
s = deque(input())
q = int(input())
cnt = 0
for i in range(q):
  query = input()
  if query == '1':
    cnt += 1
  else:
    t, f, c = query.split()
    if (f == '1' and cnt % 2 == 0) or (f == '2' and cnt % 2 == 1):
      s.appendleft(c)
    else:
      s.append(c)
if cnt % 2 == 0:
  print(''.join(s))
else:
  s.reverse()
  print(''.join(s))
