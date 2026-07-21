from itertools import count

N, K = map(int, input().split())
As = [int(n) for n in input().split()]

visited = []
visited_set = set()
now = 0
num = 0
idx = 0
for i in count():
    if now in visited_set:
        idx = visited.index(now)
        num = len(visited) - idx
        break
    visited_set.add(now)
    visited.append(now)
    now = As[now] - 1

if K <= idx:
    print(visited[K] + 1)
else:
    print(visited[idx + (K - idx) % num] + 1)
