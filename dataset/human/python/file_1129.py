N = int(input())
from collections import Counter
A = list(map(int, input().split()))
B = list(map(int, input().split()))
ca = Counter(A)
cb = Counter(B)
for i in range(1,N+1):
  if ca[i]+cb[i]>N:
    print('No')
    exit()
print('Yes')
from collections import deque
lis = [deque() for _ in range(N+1)]
da = deque(list(range(1,N+1)))
db = deque(list(range(1,N+1)))
while len(da) and len(db):
  a = da.popleft()
  b = db.popleft()
  if a==b:
    if len(db):
      db.append(b)
      b = db.popleft()
    elif len(da):
      da.append(a)
      a = da.popleft()
    else:
      for i in range(1,N+1):
        for _ in range(len(lis[i])):
          c = lis[i].popleft()
          if c!=b:
            lis[b].append(c)
            lis[i].append(b)
            ca[a] -= 1
            cb[b] -= 1
            if ca[a]==0:
              break
          else:
            lis[i].append(c)
        else:
          continue
        break
  if ca[a]>cb[b]:
    for _ in range(cb[b]):
      lis[a].append(b)
    ca[a] -= cb[b]
    cb[b] = 0
    da.appendleft(a)
  else:
    for _ in range(ca[a]):
      lis[a].append(b)
    cb[b] -= ca[a]
    ca[a] = 0
    if cb[b]>0:
      db.appendleft(b)
ans = []
for i in range(1,N+1):
  for _ in range(len(lis[i])):
    b = lis[i].popleft()
    ans.append(b)
print(*ans)
