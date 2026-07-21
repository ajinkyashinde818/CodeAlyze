from collections import deque
n, m = map(int, input().split())
g = [[] for i in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    g[a-1].append(b-1)
    g[b-1].append(a-1)

flag = [0 for i in range(n)]

def bfs(s):
    d = 0
    flag[s] = 1
    q = deque([(s, d)])

    while len(q) > 0:
        v = q.popleft()
        for i in g[v[0]]:
            if flag[i]:
                continue
            flag[i] = 1
            if v[1] < 1:
                q.append((i, d+1))
            if v[1] == 1 and i == n-1:
                return True
    return False

print("POSSIBLE" if bfs(0) else "IMPOSSIBLE")
