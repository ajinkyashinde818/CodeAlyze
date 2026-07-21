from collections import deque

d = deque(input())
q = int(input())
reverse_flag = False

for i in range(q):
  query = input().split()
  if query[0] == "1":
    reverse_flag = not reverse_flag
  else:
    if (query[1] == "1") ^ reverse_flag:
      d.appendleft(query[2])
    else:
      d.append(query[2])

print("".join(list(d)[::-1]) if reverse_flag else "".join(d))
