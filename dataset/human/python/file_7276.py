from collections import deque
S = list(input())
Q = int(input())

S = deque(S)

rev = False
for i in range(Q):
  query = list(input())
  if query[0] == '1':
    rev = not rev
  else:
    c = query[4]
    if query[2] == '1' and not rev or (rev and query[2] == '2'):
      S.appendleft(c)
    else:
      S.append(c)
      
if rev:
  S.reverse()


print(''.join(S))
