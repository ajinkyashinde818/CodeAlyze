from collections import deque
S=deque(list(input()))
Q=int(input())
ju=True
for _ in range(Q):
  l=list(input().split())
  if l[0]=="1":
    if ju:
      ju=False
    else:
      ju=True
  else:
    if ju:
      if l[1]=="1":
        S.appendleft(l[2])
      else:
        S.append(l[2])
    else:
      if l[1]=="1":
        S.append(l[2])
      else:
        S.appendleft(l[2])
if ju:
  while S:
    t=S.popleft()
    print(t,end="")
else:
  while S:
    t=S.pop()
    print(t,end="")
