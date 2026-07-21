import copy

n, k = map(int,input().split())
a = [0] + list(map(int,input().split()))

dist = [-1] * (n+1)
dist[1] = 0

cn = 1
d = 0
cycle = 0
while True:
    d += 1
    nn = a[cn]
    if d == k:
        ans = nn
        break
    if dist[nn] == -1:
        dist[nn] = copy.deepcopy(d)
    elif cycle == 0:
        cycle = d - dist[nn]
        k = (k - d) % cycle + d
    if d == k:
        ans = nn
        break
    cn = nn

print(ans)
