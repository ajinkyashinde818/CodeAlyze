from collections import deque
S = str(input())
q = int(input())
que =deque()
order = 1
for i in range (len(S)):
  que.append(S[i])
for j in range(q):
  Q = list(map(str, input().split()))
  T = Q[0]
  if T == "1":
        order *= -1
  elif T == "2":
    F = Q[1]
    C = Q[2]
    if F == "1":
      if order == 1:
        que.appendleft(C)
      elif order == -1:
        que.append(C)
    elif F == "2":
      if order == 1:
        que.append(C)
      elif order == -1:
        que.appendleft(C)
if order == 1:
  que_string = "".join(list(que))
  print(que_string)
else:
  que.reverse()
  que_string = "".join(list(que))
  print(que_string)
