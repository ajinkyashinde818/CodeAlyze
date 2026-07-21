from collections import deque

S = deque(input())
Q = int(input())
Flag = 1

for _ in range(Q):
  q = input()
  
  if q[0] == "1":
    Flag *= -1
  
  if q[0] == "2":
    if Flag > 0:
      if q[2] == "1":
        S.appendleft(q[4])
      else:
        S.append(q[4])
    else:
      if q[2] == "1":
        S.append(q[4])
      else:
        S.appendleft(q[4])
  
if Flag < 0:
  S.reverse()

print("".join(S))
