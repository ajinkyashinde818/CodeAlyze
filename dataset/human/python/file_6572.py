from collections import deque
count = 0
s = deque(list(input()))
q = int(input())

for i in range(q):
  a = list(input().split())
  if a[0] == '1':
    count += 1
    continue
    
  if count%2 == 0:
    if a[0] == '2':
      if a[1] == '1':
        s.appendleft(a[2])
      elif a[1] == '2':
        s.append(a[2])
        
  if count%2 == 1:
    if a[0] == '2':
      if a[1] == '1':
        s.append(a[2])
      elif a[1] == '2':
        s.appendleft(a[2])
      
ans = ''.join(s)
print(ans if count%2 == 0 else ''.join(list(reversed(ans))))
