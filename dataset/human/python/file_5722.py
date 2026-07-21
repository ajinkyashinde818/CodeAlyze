from collections import deque
s = deque(input())
cou = 0
while len(s)!=0:
  a = s[0]
  b = s[-1]
  if a=='x' and b!='x':
    cou += 1
    s.popleft()
  elif a!="x" and b=='x':
    cou += 1
    s.pop()
  elif a=="x" and b=='x':
    if len(s)==1:
      s.popleft()
    else:   
      s.popleft()
      s.pop()
  elif a==b:
    if len(s)==1:
      s.popleft()
    else:   
      s.popleft()
      s.pop()
  else:
    print(-1)
    exit()
print(cou)
