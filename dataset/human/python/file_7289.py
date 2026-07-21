import collections
S = collections.deque(list(input()))
N = int(input())
parity = True
for i in range(N):
  query = input().split()
  if query[0] == "1":
    if parity == True:
      parity = False
    else:
      parity = True
  if query[0] == "2":
    if parity:
      if query[1] == "1":
        S.appendleft(query[2])
      else:
        S.append(query[2])
    else:
      if query[1] == "1":
        S.append(query[2])
      else:
        S.appendleft(query[2])

Sstr = ""
if parity:
  for i in range(len(S)):
    Sstr = Sstr + S.popleft()
else:
  for i in range(len(S)):
    Sstr = Sstr + S.pop()
print(Sstr)
