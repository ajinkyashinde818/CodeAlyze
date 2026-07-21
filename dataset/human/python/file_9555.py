import sys
input = sys.stdin.readline

n, k = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]

visited = set()
visited.add(0)
now = 0
route = [0]

for i in range(1, n + 5):
    now = a[now] - 1
    if now in visited:
        break
    route.append(now)
    visited.add(now)

start = route.index(now)
loop = i - start

if k <= start:
    print(route[k] + 1)
else:
    k -= start
    k %= loop
    route = route[start:]
    print(route[k] + 1)
