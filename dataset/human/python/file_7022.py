from collections import deque

s = input() 
s_queue = deque(s)
q = int(input())

inverted = False

for _ in range(q):
  query = input()
  if query[0] == "1":
    inverted = not inverted 
  else:
    ti, fi, ci = query.split()
    if fi == "1" and inverted:
      s_queue.append(ci)
    elif fi == "1" and not inverted:
      s_queue.appendleft(ci)
    elif fi == "2" and inverted:
      s_queue.appendleft(ci)
    else:
      s_queue.append(ci)

if inverted:
  print("".join(s_queue)[::-1])
else:
  print("".join(s_queue))
