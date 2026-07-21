from collections import deque
S = input()
Q = int(input())
T = [input() for i in range(Q)]

d =deque(S)

count = True

for i in range(Q):
  t = T[i]
  if(int(t[0]) == 1):
    count = not count
  else:
    if(int(t[2]) == 1):
      if(count):
        d.appendleft(t[4])
      else:
        d.append(t[4])
    else:
      if(count):
        d.append(t[4])
      else:
        d.appendleft(t[4])

ans = list(d)

if(count):
  print("".join(ans))
else:
  print("".join(ans[::-1]))
