from collections import deque
n, k = list(map(int, input().split()))
a = [0, ] + list(map(int, input().split()))
stack = deque([1, ])
visited = [0] * (n + 1)
hist = []
open = []
loop = []
while stack:
    now = stack.popleft()
    if visited[now] == 1:
        b = hist.index(now)
        open = hist[:b]
        loop = hist[b:]
        break
    next = a[now]
    visited[now] = 1
    hist.append(now)
    stack.append(next)
if k < len(open):
    print(open[k])
else:
    print(loop[(k - len(open)) % len(loop)])
