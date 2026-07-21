import sys
from collections import deque
N,K = map(int,input().split())
A = [0] + list(map(int,input().split()))
G = dict([(i,[]) for i in range(1,N+1)])
for i in range(1,N+1):
  G[i].append(A[i])

l = deque([A[1]])
seen = [False for i in range(N+1)]
seen[1] = True
d = [0 for i in range(N+1)]
d[A[1]] = 1
if A[1] == 1:
  print(1)
  sys.exit()

for i in range(K):
  v = l.popleft()
  if seen[v] == False:
    seen[v] = True
    l.append(A[v])
    if seen[A[v]] == True: 
      a = d[A[v]]
      b = d[v] + 1 - a
    else:  
      d[A[v]] = d[v] + 1
  else:  
    start = v
    break  
  if i == K-1:
    print(v)
    sys.exit()

kaisu = (K-a)%b
p = start
for i in range(kaisu):
  p = A[p]
print(p)
