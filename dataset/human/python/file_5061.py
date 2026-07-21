from collections import deque

N,M=map(int,input().split())
graph=[[] for _ in range(N)]
for _ in range(M):
    a,b=map(int,input().split())
    a-=1
    b-=1
    graph[a].append(b)
    graph[b].append(a)

def dfs(start):
    d=[float("inf")]*N
    d[start]=0

    queue=deque([start])
    while queue:
        x=queue.popleft()
        for y in graph[x]:
            if d[y]!=float("inf"):
                continue
            d[y]=d[x]+1
            queue.append(y)
    
    return d

d=dfs(0)
if d[-1]==2:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
