from collections import deque

S=deque(input())
Q=int(input())

t=True

for i in range(Q):
  query=input().split()
  if query[0]=='1':
    t = not t
  else:
    if (t and query[1]=='1') or (not t and query[1]=='2'):
      S.appendleft(query[2])
    else:
      S.append(query[2])

S=''.join(S)

if not t:
  S=S[::-1]

print(S)
