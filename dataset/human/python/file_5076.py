from collections import deque

def bfs(si, ei):
  q = deque()
  q.append([si,0])
  done = set([si])
  while len(q) > 0:
    prvi, prvcnt = q.popleft()
    for i in g[prvi]:
      if i in done:
        continue
        
      else:
        if prvcnt + 1 > 2:
          continue
          
        if i == ei: return 'POSSIBLE'
        else:
          q.append([i, prvcnt+1])
          done.add(i)
  return 'IMPOSSIBLE'

N,M = map(int,input().split())
g = {i:[] for i in range(N)}
for _ in range(M):
  a, b = map(int,input().split())
  g[a-1].append(b-1)
  g[b-1].append(a-1)

print(bfs(0,N-1))
