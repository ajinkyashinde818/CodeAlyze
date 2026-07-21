from collections import deque
s = deque(input())
n = int(input())
f = 0
for i in range(n):
  l = list(map(str, input().split()))
  if l[0] == "2":
    if (l[1] == "1" and f == 0) or (l[1] == "2" and f == 1):
      s.appendleft(l[2])
    else:
      s.append(l[2])
  else:
    if f == 0:
      f = 1
    else:
      f = 0
if f == 1:
  s.reverse()
print("".join(s))
