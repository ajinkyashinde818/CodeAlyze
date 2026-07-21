import sys
N, K = map(int, sys.stdin.readline().split())
A = list(map(int, sys.stdin.readline().split()))

x = A[0]
visited = [0] * N
visited[0] = 1
visited_num = [1]
for i in range(N):
    if visited[x - 1] == 1:
        b = i + 1
        break
    visited[x - 1] = 1
    visited_num.append(x)
    x = A[x - 1]
    
for j, p in enumerate(visited_num):
    if p == x:
        a = j
        
if K < a:
    ans = visited_num[K]
else:
    n = (K - a) % (b - a)
    ans = visited_num[a + n]
    
print(ans)
