import sys
n, k = map(int, input().split())
a = list(map(int, input().split())) 

visited = [None]*n
cur = 0
for i in range(k):
    if visited[cur] is None:
        visited[cur] = i
        cur = a[cur]-1
    else:
        break
else:
    print(cur+1)
    sys.exit()

k -= i
k %= i-visited[cur]

for i in range(k):
    cur = a[cur]-1

print(cur+1)
