from collections import deque

S = deque(input())
q = int(input().strip())


rev_count = 0
for i in range(q):
  query = input()
  if query[0] == "1":
    rev_count += 1
  elif query[0] == "2":
    query = query.strip().split(" ")
    if rev_count & 1 == 1:
      if query[1] == "1":
        S.append(query[2])
      else:
        S.appendleft(query[2])
    else:
      if query[1] == "1":
        S.appendleft(query[2])
      else:
        S.append(query[2])

if rev_count & 1 == 1:
  S.reverse()

print("".join(S))
