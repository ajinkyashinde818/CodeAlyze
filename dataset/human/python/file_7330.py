from collections import deque

S = deque(input())
Q = int(input())
flip = False # False: left side is the head
for i in range(Q):
  Query_i = list(map(str, input().split()))
  if Query_i[0]=='1':
    flip = not flip
  elif Query_i[1] == '1' and not flip:
    S.appendleft(Query_i[2])
  elif Query_i[1] == '1' and flip:
    S.append(Query_i[2])
  elif Query_i[1] == '2' and not flip:
    S.append(Query_i[2])
  elif Query_i[1] == '2' and flip:
    S.appendleft(Query_i[2])
if flip:
  S.reverse()
print(''.join(S))
