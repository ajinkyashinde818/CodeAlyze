from collections import deque
s = deque(input())

n = int(input())
l = []

base = 1

for i in range(n):
  l=list(input().split())
  if l[0] == '1':
    base = base *-1
  else:
    if l[1] =='1' and base == 1 :
      s.appendleft(l[2])
    elif l[1] =='2' and base == 1 :
      s.append(l[2])
    elif l[1] =='1' and base == -1 :
      s.append(l[2])
    elif l[1] =='2' and base == -1 :
      s.appendleft(l[2])

if base ==-1:
  s=''.join(list(reversed(s)))
      
print("".join(s))
