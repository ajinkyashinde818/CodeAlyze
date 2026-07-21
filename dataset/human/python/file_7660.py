from collections import deque
s = input()
qq = int(input())
q = []
for _ in range(qq):
  q.append(input())
h = 1
for i in q:
  if i[0] == '1':
    h*=-1
if h == -1:
  ss = ''
  for i in reversed(s):
    ss += i
  s = ss
d = deque()
d.append(s)
h = 1
for i in q:
  if i[0] == '1':
    h*=-1
  else:
    if (h == 1 and i[2] == '1') or (h == -1 and i[2] == '2'):
      d.appendleft(i[4])
    else:
      d.append(i[4])
p = ''
if h == -1:
  for i in reversed(d):
    p += i
else:
  for i in d:
    p += i
print(p)
