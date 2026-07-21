N, M = map(int, input().split())

edges = {i : [] for i in range(1, N+1)}
visited = [False for _ in range(N+1)]

for _ in range(M):
  a, b = map(int, input().split())
  edges[a].append(b)
  edges[b].append(a)

def dfs(n, count):
  # 定期便2つでは行けない
  if count == 3:
    return False
  if n == N:
    return True
  visited[n] = True
  
  for edge in edges[n]:
    if visited[edge]:
      continue
    if dfs(edge, count + 1):
      return True
  
  return False

print("POSSIBLE" if dfs(1, 0) else "IMPOSSIBLE")
