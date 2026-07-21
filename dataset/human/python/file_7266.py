from collections import deque
S = deque(list(input()))
Q = int(input())

flag = False
for _ in range(Q):
  query = input().split()
  if query[0] == '1':
    flag = not flag
  elif query[0] == '2':
    left = query[1] == '1'
    if flag:
      left = not left
    if left:
      S.appendleft(query[2])
    else:
      S.append(query[2])

if flag:
  print(''.join(reversed(S)))
else:
  print(''.join(S))
