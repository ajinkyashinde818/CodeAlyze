from collections import deque

S = input()
Q = int(input())

deq = deque(S)

direction = 1

for _ in range(Q):
  q = input()
  if q == '1':
    direction *= -1
  else:
    _, f, c = q.split()
    if direction > 0:
      if f == '1':
        deq.appendleft(c)
      else:
        deq.append(c)
    else:
      if f == '1':
        deq.append(c)
      else:
        deq.appendleft(c)

if direction < 0:
  deq.reverse()
        
print(''.join(deq))
