from collections import deque

s = deque(input())
q = int(input())
flg = 0

for _ in range(q):
  Q = [x for x in input().split()]
  if Q[0] == '1':
    flg += 1
  else:
    if (Q[1] == '1' and flg%2==0) or (Q[1] == '2' and flg%2==1):
      s.appendleft(Q[2])
    else:
      s.append(Q[2])
if flg%2==1:
  s.reverse()

print('' . join(s))
