from collections import deque
s = deque(list(input()))
q = int(input())
hanten = 0
for i in range(q):
  nyuuryoku = input().split()
  n = nyuuryoku[0]
  if len(nyuuryoku) == 1:
    hanten += 1
    continue
  else:
    f = int(nyuuryoku[1])
    c = nyuuryoku[2]
    if hanten%2 == 0:
      if f ==1:
        s.appendleft(c)
      else:
        s.append(c)
    else:
      if f == 1:
        s.append(c)
      else:
        s.appendleft(c)
if hanten%2 == 1:
  s.reverse()
ans = "".join(s)
print(ans)
