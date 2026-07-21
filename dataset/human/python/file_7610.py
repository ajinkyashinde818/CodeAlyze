from collections import deque

s = input()
a = deque()
for i in s:
  a.append(i)
q = int(input())
rev = 0     # 反転をフラグで持って、実際には反転させない
for i in range(q):
  s = input()
  if s[0] == '1':
    rev ^= 1
  else:
    b = (int(s[2]) - 1) ^ rev
    if b:
      a.append(s[4])
    else:
      a.appendleft(s[4])
if rev:
  a.reverse()
for i in a:
  print(i, end="")
