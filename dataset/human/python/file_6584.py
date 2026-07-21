s = input()
q = int(input())

from collections import deque

ss = deque(s)
flg = True

for i in range(q):
  t = input().split()
  if t[0] == '1':
    flg = not flg
  else:
    if t[1] == '2':
        ss.append(t[2]) if flg else ss.appendleft(t[2])
    else:
        ss.append(t[2]) if not flg else ss.appendleft(t[2])

ss = list(ss)

print("".join(ss)) if flg else print("".join(ss[::-1]))
