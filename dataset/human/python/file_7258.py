import sys
readline = sys.stdin.readline

S = readline().rstrip()

from collections import deque
S = deque(S)

Q = int(readline())
turn = False
for i in range(Q):
  query = readline().split()
  if query[0] == "1":
    turn ^= True
  elif query[0] == "2":
    if query[1] == "1":
      if turn:
        S.append(query[2])
      else:
        S.appendleft(query[2])
    elif query[1] == "2":
      if turn:
        S.appendleft(query[2])
      else:
        S.append(query[2])

S = "".join(S)
if turn:
  S = S[::-1]
  
print(S)
