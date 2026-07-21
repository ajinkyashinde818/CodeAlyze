def solve():
    N, K = map(int, input().split())
    A = [0]+list(map(int, input().split()))
    visited = [-1]*(N+1)
    visited[1] = 0
    now = 1
    for i in range(1,K+1):
        now = A[now]
        if visited[now]>=0:
            break
        visited[now] = i
    if i==K:
        ans = now
    else:
        num = (K-visited[now])%(i-visited[now])+visited[now]
        ans = visited.index(num)
    return ans
print(solve())
