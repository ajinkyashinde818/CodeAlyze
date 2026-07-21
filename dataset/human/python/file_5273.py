from collections import deque
n,m = map(int,input().split())

adj = [[] for i in range(n)]
dist = [-1]*n
for i in range(m):
    a,b = map(int,input().split())
    adj[a-1].append(b-1)
    adj[b-1].append(a-1)
    
q = deque()
dist[0] = 0
q.append(0)

while len(q) > 0:
    x = q.popleft()
    
    for f in adj[x]:
        if dist[f] != -1:
            continue
        
        dist[f] = dist[x] + 1
        q.append(f)
     
if dist[n-1] == 2:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
