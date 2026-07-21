import sys, math, itertools, collections, bisect
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
inf = float('inf') ;mod = 10**9+7
mans = inf ;ans = 0 ;count = 0 ;pro = 1

n,k = map(int,input().split())
A = list(map(int,input().split()))
for i in range(n):A[i] -= 1
visited = [-1] * n
visited[0] = 0
now = 0
count = 0
while True:
  now = A[now]
  count += 1
  if count == k:
    print(now+1)
    exit()
  if visited[now] == -1:
    visited[now] = count
  else:
    rooplen = count-visited[now]
    k -= visited[now]
    k = k % rooplen
    break
  # print(visited)

visited = [-1] * n
count = 0
while True:
  # print(count,k,now)
  if count == k:
    print(now+1)
    exit()
  if visited[now] == -1:
    visited[now] = count
  now = A[now]
  count += 1
