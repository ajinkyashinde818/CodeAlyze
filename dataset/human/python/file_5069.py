from collections import deque
n,m = map(int,input().split())

Map = [[] for i in range(n)]
for i in range(m):
    a,b = map(int,input().split())
    Map[a-1].append(b-1)
    Map[b-1].append(a-1)

q = deque()
q.append((0,0))
while q:
    now,cnt = q.popleft()
    if now==n-1 and cnt==2:
        print('POSSIBLE')
        exit()
    if cnt>=2:
        continue
    for index in Map[now]:
        q.append((index,cnt+1))
print('IMPOSSIBLE')
