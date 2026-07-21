from collections import deque
S = deque(input())
Q = int(input())
state = 0
for i in range(Q):
  m = input().split()
  if len(m)==1:
    state = (state+1)%2
  else:
    f = m[1]
    if f=='1':
      if state == 1:
        S.append(m[2])
      else:
        S.appendleft(m[2])
    else:
      if state==1:
        S.appendleft(m[2])
      else:
        S.append(m[2])
if state ==1:
  S = list(S)[::-1]
print(''.join(S))
