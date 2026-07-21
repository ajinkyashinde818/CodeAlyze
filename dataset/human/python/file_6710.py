from collections import deque
S = deque(list(input()))
Q = int(input())

r_count = 0
for query in range(Q):
  query = deque(list(input().split()))
  t = query[0]
  if (t == '1'):
    r_count += 1
  elif (t == '2'):
    f = query[1]
    if(f == '1' and (r_count % 2 == 0)):
      S.appendleft(query[2])
    elif(f == '1' and (r_count % 2 == 1)):
      S.append(query[2])
    elif(f == '2' and (r_count % 2 == 0)):
      S.append(query[2])
    elif(f == '2' and (r_count % 2 == 1)):
      S.appendleft(query[2])

if (r_count % 2 == 1):
  for i, s in enumerate(reversed(S)):
    if (i == len(S) - 1):
      print(s)
    else:
      print(s, end="")
else:
  for i, s in enumerate(S):
    if (i == len(S) - 1):
      print(s)
    else:
      print(s, end="")
