from collections import deque
s = deque(input())
n = int(input())
q = []
for i in range(n):
  query = list(input().split())
  q.append(query)
  
a = 1
for i in range(n):
  if int(q[i][0]) == 1:
    a *= -1
  else:
    if int(q[i][1]) == 1:
      if a > 0:
        s.appendleft(q[i][2])
      else:
        s.append(q[i][2])
    else:
      if a > 0:
        s.append(q[i][2])
      else:
        s.appendleft(q[i][2])
s = list(s)
s = "".join(s)
if a > 0:
  print(s)
else:
  s = s[::-1]
  print(s)
