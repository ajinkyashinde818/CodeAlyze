def dfs(i, p):
    if(p == n):
        return 1
    if(i == 2):
        return 0
    ret = 0
    for q in adj[p]:
        ret += dfs(i+1, q)
    return ret

n, m = map(int, input().split())
adj = [[] for i in range(n+1)]
for i in range(m):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)
ans = dfs(0, 1)

print("POSSIBLE" if(ans) else "IMPOSSIBLE")
