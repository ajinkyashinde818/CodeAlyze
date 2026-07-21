from collections import deque
d = deque()
d.extend(input())
q = int(input())
r = False
for i in range(q):
  qu = input().split()
  if qu[0] == "1":
    r = not r
  else:
    if (qu[1] == "1" and not r) or (qu[1] == "2" and r):
      d.extendleft(qu[2])
    else:
      d.extend(qu[2])

if r:
  d.reverse()

print(''.join(list(d)))
