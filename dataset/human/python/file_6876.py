from collections import deque

c = deque(input())
n = int(input())
head = 1

for _ in range(n):
  now = list(input().split())
  if now[0] == "1":
    head *= -1
  else:
    if now[1] == "1":
      if head == 1:
        c.appendleft(now[2])
      else:
        c.append(now[2])
    else:
      if head == 1:
        c.append(now[2])
      else:
        c.appendleft(now[2])
print("".join(c) if head == 1 else "".join([c.pop() for _ in range(len(c))]))
