from time import time
N, K = list(map(int, input().split()))
A = list(map(int, input().split()))
L = [-1 for i in range(N)]

visited = []
now = 0
loopstarts = None
looplength = None
t0 = time()

for i in range(N):
    if L[now] != -1:
        break
    else:
        L[now] = i
        visited.append(now)
        now = A[now]-1

loopstarts = visited.index(now)
looplength = len(visited)-loopstarts

if K < loopstarts:
    print(visited[K]+1)
else:
    print(visited[loopstarts+(K-loopstarts)%looplength]+1)
# print(time()-t0)
