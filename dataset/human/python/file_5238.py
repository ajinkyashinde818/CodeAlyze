import sys
input = sys.stdin.readline
n,m=map(int,input().split())
g=[[]for _ in range(n)]
for _ in range(m):
    a,b=map(int,input().split())
    g[a-1].append(b-1)
    g[b-1].append(a-1)

u=g[0]
for v in u:
    if n-1 in g[v]:
        print("POSSIBLE")
        exit()
print("IMPOSSIBLE")
