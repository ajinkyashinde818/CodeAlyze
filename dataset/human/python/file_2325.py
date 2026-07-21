from math import ceil
D,G = map(int,input().split())
list = [list(map(int,input().split())) for _ in range(D)]

def dfs(G,i):
    if i <= 0:
        return float('inf')
    n = min(ceil(G/(100*i)),list[i-1][0])
    s = 100*i*n
    if n == list[i-1][0]:
        s += list[i-1][1]
    if G > s:
        n += dfs(G-s,i-1)
    return min(n,dfs(G,i-1))

print(dfs(G,D))
