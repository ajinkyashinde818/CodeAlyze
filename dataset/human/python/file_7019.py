from collections import deque

s = input()
que = deque(s)

T_F = True

for i in range(int(input())):
  query = input()
  if query[0] == '1':
    T_F = not T_F
  elif (query[2] == '1' and T_F) or (not query[2] == '1' and not T_F):
    que.appendleft(query[4])
  else:
    que.append(query[4])
if T_F:
  print(''.join(que))
else :
  print(''.join(reversed(que)))
