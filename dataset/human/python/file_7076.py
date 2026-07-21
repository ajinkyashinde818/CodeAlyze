from collections import deque
s = input()
n = int(input())
d = deque(s)

now_reverse = False

for _ in range(n):
  query = input()

  if query == '1':
    now_reverse = not now_reverse
    continue

  
  _,f,c = query.split()
  if f == '1' and now_reverse:
    d.append(c)
  elif f == '1' and not now_reverse:
    d.appendleft(c)
  elif f == '2' and now_reverse:
    d.appendleft(c)
  else:
    d.append(c)
  
if now_reverse:
  d = reversed(list(d))
else:
  d =list(d)

for c in d:
  print(c,end='')
print()
