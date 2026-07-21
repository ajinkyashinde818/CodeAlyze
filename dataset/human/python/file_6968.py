from collections import deque
S = input()
d = deque()
for s in S:
  d.append(s)
flag = True # 正順ならTrue, 逆順ならFalse
for i in range(int(input())):
  query = input().split()
  if query[0] == '1':
    flag = not flag
  if query[0] == '2':
    if query[1] == '1':
      if flag:
        d.appendleft(query[2])
      if not flag:
        d.append(query[2])
    if query[1] == '2':
      if flag:
        d.append(query[2])
      if not flag:
        d.appendleft(query[2])
if flag:
  for i in d:
    print(i, end='')
if not flag:
  for i in reversed(d):
    print(i, end='')
