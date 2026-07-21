from collections import deque

s = deque(input())
reverse = 0
q = int(input())

for _ in range(q):
  query = input()
  if query == '1':
    reverse = 1 - reverse
  else:
    _,f,c = query.split()
    if f == '1':
      if reverse:
        s.append(c)
      else:
        s.appendleft(c)
    else:
      if reverse:
        s.appendleft(c)
      else:
        s.append(c)
        
  
if reverse:
  s.reverse()

print(''.join(s))
