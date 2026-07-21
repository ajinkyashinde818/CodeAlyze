d,g = map(int, input().split())
pc = [0] + [[int(i) for i in input().split()] for _ in range(d)]

def dfs(G, i):
    if i == 0:
        return 1e9
    n = min(G // (i*100), pc[i][0])
    s = n * i * 100
    if n == pc[i][0]:
        s += pc[i][1]
    if s < G:
        n += dfs(G-s, i-1)
    return min(n, dfs(G, i-1))

print(dfs(g, d))
