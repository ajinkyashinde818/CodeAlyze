"""
N towns
teleporter each town
teleporter at town i -> town A_i
k-times teleporter after starting at town 1
"""

from collections import deque

n, k = map(int, input().split())
a = list(map(lambda x: int(x) - 1, input().split()))

visited = [0] * n
path = deque()
cur = 0

while not visited[cur]:
    visited[cur] = 1
    path.append(cur)
    cur = a[cur]

while path[0] != cur and k > 0:
    k -= 1
    path.popleft()

#print(path)
if k == 0:
    print(path[0] + 1)
else:
    print((path[k % len(path)]) + 1)
