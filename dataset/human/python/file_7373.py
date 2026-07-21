from collections import deque
S = input()
ds = deque(S)
Q = int(input())
query = []
for i in range(Q):
  tq = list(input().split())
  if (len(tq) == 1):
    query.append(1)
  if (len(tq) == 3):
    query.append([int(tq[1]),tq[2]])
eo = 1
for q in query:
  if q == 1:
    eo = eo*(-1)
  else:
    eoq = eo*q[0]
    if eoq == 1 or eoq == -2:
      ds.extendleft(q[1])
    else:
      ds.extend(q[1])
jds = "".join(ds)
if eo == -1:
  jds = jds[::-1]
print(jds)
