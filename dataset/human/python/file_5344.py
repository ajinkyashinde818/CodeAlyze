from collections import deque

n,m=map(int,input().split())
ab=[list(map(int,input().split())) for _ in range(m)]
g=[[] for _ in range(n+1)]

for a,b in ab:
    g[a].append(b)
    g[b].append(a)

q=deque([(1,0)])
visit=[0]*(n+1)

while len(q)>0:
    u,cnt=q.popleft()

    visit[u]=1

    if u==n and cnt==2:
        print('POSSIBLE')
        exit(0)
    
    for v in g[u]:
        if visit[v] or cnt==2:
            continue

        q.append((v,cnt+1))

print('IMPOSSIBLE')
