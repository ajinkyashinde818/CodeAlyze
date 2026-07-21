from collections import deque
S = deque(list(input().strip()))
Q = int(input().strip())
flag = 1
for i in range(Q):
  line = input().strip()
  if len(line) == 1:
    flag = 1 - flag
  else:
    _, F, C = line.strip().split()
    if flag:
      if int(F) == 1:
        S.appendleft(C)
      else:
        S.append(C)
    else:
      if int(F) == 1:
        S.append(C)
      else:
        S.appendleft(C)

if flag:
  print(''.join(S))
else:
  print(''.join(list(reversed(S))))
