from collections import deque
S = deque(input())
Q = int(input())
reverse = 0
for i in range(Q):
  Query = list(input().split())
  if Query[0] == "1":
    reverse = (reverse + 1) % 2
  if Query[0] == "2":
    f = int(Query[1])
    c = Query[2]
    if (f + reverse) % 2 == 1:
      S.appendleft(c)
    else:
      S.append(c)

S = "".join(list(S))
 
if reverse == 0:
  print(S)
else:
  print(S[::-1])
