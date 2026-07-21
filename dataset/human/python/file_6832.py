S = str(input())
Q = int(input())

from collections import deque
s_list = [s for s in S]
que = deque(s_list)

mode = 1
for _ in range(Q):
  q_in = str(input())

  if q_in == '1':
    mode *= -1
    continue

  else:
    t, f_in, c = map(str, q_in.split())
    f = int(f_in)
    if mode == -1:
      if f_in == '1':
        f = 2
      else:
        f = 1
    if f == 1:
      que.appendleft(c)
    else:
      que.append(c)

if mode == -1:
  que = reversed(que)

ans = ''.join(que)
print(ans)
