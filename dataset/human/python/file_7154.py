from collections import deque

d = deque()
s = input()
d.append(s)
rev = 0
q = int(input())

for i in range(q):
  query = list(input().split())
  if (int(query[0]) == 1):
    rev = (rev + 1) % 2
  else:
    if ((int(query[1]) + rev) % 2 == 0):
      d.append(query[2])
    else:
      d.appendleft(query[2])

ans = ''.join(list(d))
if rev == 1:
  ans = ans[::-1]

print(ans)
