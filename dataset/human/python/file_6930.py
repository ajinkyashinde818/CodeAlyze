from collections import deque
que1 = deque([])
que2 = deque([])
s = input()
q = int(input())
rev = 1
for i in range(q):
  t = input()
  
  if t == '1':
    rev *= -1
  else:
    x,y,sr = t.split()
    if (rev == 1 and y == '2') or (rev == -1 and y == '1'):
      que2.append(sr)
    else:
      que1.appendleft(sr)

s = ''.join(que1+deque([s])+que2)     
if rev == -1:
  s = s[::-1]
  
print(s)
