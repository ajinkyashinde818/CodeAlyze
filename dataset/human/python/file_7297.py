from collections import deque
S = deque(input())
Q = int(input())
d = 0 # d=0:right, d=1:left
for i in range(Q):
  I = list(input().split())
  if I[0] == "1":
    d ^= 1
  else:
    if d + int(I[1]) == 2:
      S.append(I[2])
    else:
      S.appendleft(I[2])
if d == 1:
  S.reverse()
for s in S:
  print(s, end="")
print()
