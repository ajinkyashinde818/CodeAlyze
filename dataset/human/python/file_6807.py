import collections
S = collections.deque(input())
Q = int(input())
reverse = False
for i in range(Q):
  q = input()
  if q == "1":
    reverse = not reverse
  else:
    q,f,c = q.split()
    if (f == "1" and not reverse) or (f == "2" and reverse):
      S.appendleft(c)
    else:
      S.append(c)
if not reverse:
  print("".join(S))
else:
  print("".join(reversed(S)))
