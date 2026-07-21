from collections import deque

N,M=map(int,input().split())

graph=[[]for _ in range(N+1)]

for _ in range(M):
    A,B=map(int,input().split()) # 入力に合わせて適宜変更
    graph[A].append(B)
    graph[B].append(A)

dist=[-1]*(N+1) # 出力に合わせて適宜変更
dist[0]=0
dist[1]=0

D=deque()
D.append(1)

while D:
    V=D.popleft()
    for i in graph[V]:
        if dist[i]!=-1:
            continue
        dist[i]=dist[V]+1 # 出力に合わせて適宜変更（答えに直結するので最重要）
        D.append(i)

print(['IMPOSSIBLE','POSSIBLE'][dist[N]==2])
