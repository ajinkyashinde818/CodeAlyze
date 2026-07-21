from collections import deque
S=deque(input())
Q=int(input())
isForward = True
for _ in range(Q):
  v = input().split()
  if v[0] == '1':
    isForward = (isForward == False)
    continue
  if isForward:
    if v[1] == '1':
      S.appendleft(v[2])
    else:
      S.append(v[2])
  else:
    if v[1] == '1':
      S.append(v[2])
    else:
      S.appendleft(v[2])
if isForward == False:
  S = reversed(S)
print(''.join(S))
