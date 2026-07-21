from collections import deque
S = deque([input()])
Q = int(input())
is_reverse = False

for _ in range(Q):
  inp = input().split()
  if len(inp) == 1:
    if is_reverse:
      is_reverse = False
    else:
      is_reverse = True
  else:
    _, f, c = inp
    if f == '1':
      if is_reverse:
        S.append(c)
      else:
        S.appendleft(c)
    else:
      if is_reverse:
        S.appendleft(c)
      else:
        S.append(c)
if is_reverse:
  ans = "".join(S)
  print(ans[::-1])
else:
  print("".join(S))
