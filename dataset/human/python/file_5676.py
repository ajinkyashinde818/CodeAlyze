from collections import deque

s = deque(input())

cnt = 0
while len(s) > 1:
  a,b = s[0],s[-1]
  if a == b:
    s.pop()
    s.popleft()
  elif a == 'x':
    cnt += 1
    s.popleft()
  elif b == 'x':
    cnt += 1
    s.pop()
  else:
    break
else:
  print(cnt)
  exit()

print(-1)
