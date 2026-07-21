from collections import deque

def bfs(s):
    q = deque()
    q.append(s)
    dist[s] = 0
    while q:
        p = q.popleft()
        if dist[a[p]] == -1:
            dist[a[p]] = dist[p] + 1
            q.append(a[p])
        else:
            return [dist[a[p]], dist[p] + 1]

n, k = map(int, input().split())
a = list(map(int, input().split()))
a.insert(0, 0)
dist = [-1] * (n + 1)
x = bfs(1)
y = [0, x[1] - x[0], k - x[0]]
l = y[2] % y[1]
ans = l + x[0]
if k <= x[0]:
    ans = k
for i in range(1, n + 1):
    if dist[i] == ans:
        print(i)
        exit()
