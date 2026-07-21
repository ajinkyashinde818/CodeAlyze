from collections import deque
S = list(map(str, input()))
Q = int(input())

ans_lst = deque(S)
rev = False
for i in range(Q):
  QUERY = list(map(str, input().split()))
  if QUERY[0] == '1':
    if rev:
      rev = False
    else:
      rev = True
  else:
    if rev:
      if QUERY[1] == '1':
        ans_lst.append(QUERY[2])
      else:
        ans_lst.appendleft(QUERY[2])
    else:
      if QUERY[1] == '1':
        ans_lst.appendleft(QUERY[2])
      else:
        ans_lst.append(QUERY[2])    

if rev:
  ans_lst.reverse()
  print(''.join(ans_lst))
else:
  print(''.join(ans_lst))
