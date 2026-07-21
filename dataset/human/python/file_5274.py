N,M = map(int,input().split())
AB = [list(map(int,input().split())) for _ in range(M)]

EDGE = [[] for _ in range(N+1)]

for a,b in AB:
  EDGE[a].append(b)
  EDGE[b].append(a)
  
def dfs(p,u,d):
  if u == N:
    return True
  
  if d == 0:
    return False
  
  ans = False
  
  for v in EDGE[u]:
    if v == u:
      continue
      
    ans |= dfs(u,v,d-1)
  
  return ans

ans = dfs(-1,1,2)

s = 'POSSIBLE' if ans else 'IMPOSSIBLE'

print(s)
