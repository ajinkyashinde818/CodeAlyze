from collections import defaultdict

n, k = list(map(int, input().split()))
a = list(map(int, input().split()))
for i in range(n):
    a[i] -= 1

loop = [0]
town = 0
visited = defaultdict(lambda: None)
visited[town] = 0

period = 0
for i in range(1, k+1):
    town = a[town]
    if visited[town] != None:
        offset = visited[town]
        period = i - offset 
        break
    else:
        loop.append(town)
        visited[town] = i

if period == 0:
    print(town+1)
else:
    print(loop[offset+((k-offset)%period)]+1)
