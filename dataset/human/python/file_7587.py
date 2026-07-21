from collections import deque
s = input()
q = int(input())

text = deque(s)
readleft = True


for _ in range(q):
  query = input().rstrip().split()
  if query[0] == "1":
    readleft = not(readleft)
  else:
    addtop = 2 - int(query[1])
    addleft = (addtop == readleft)
    if addleft:
      text.appendleft(query[2])
    else:
      text.append(query[2])

if readleft:
  while text != deque():
    print(text.popleft(), end="")
  print()
else:
  while text != deque():
    print(text.pop(), end="")
  print()
