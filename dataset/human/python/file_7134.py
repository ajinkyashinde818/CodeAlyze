from collections import deque

s = list(input())
q = int(input())
query = [list(input().split()) for i in range(q)]
now = 0
a = deque(s)
for i in query:
  if i[0] == "1":
    now ^= 1
  elif i[0] == "2":
    f,c = int(i[1]),i[2]
    if (f+now) % 2:
      a.appendleft(c)
    else:
      a.append(c)
if now:
  a.reverse()
ans = "".join(a)
print(ans)
