import sys
sys.setrecursionlimit(4100000)
n, m = map(int, input().split())
g = [[] * n for i in range(n)]
for i in range(m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    g[u].append(v)
    g[v].append(u)

flag = False
def dfs(now, prev, cnt):
    global flag
    if cnt == 2:
      if now == n-1:
        flag = True
    for next in g[now]:
        if next != prev and cnt < 2:
            dfs(next, now, cnt+1)
    return flag
            
ans = dfs(0,-1,0)
if ans:
  print('POSSIBLE')
else:
  print('IMPOSSIBLE')
