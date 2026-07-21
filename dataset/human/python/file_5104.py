import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

n, m = map(int, readline().split())
graph = [[] for _ in range(n + 1)]
for i in range(m):
    a, b = map(int, readline().split())
    graph[a].append(b)
    graph[b].append(a)


def dfs(s):
    from collections import deque
    check = [0] * (n + 1)
    stack = deque([s])
    check[s] = 0
    while stack:
        now = stack.pop()
        for next in graph[now]:
            if check[next] != 0 and next != n:
                continue
            if next == n and check[now] == 1:
                print('POSSIBLE')
                exit()
            check[next] += check[now] + 1
            stack.appendleft(next)


dfs(1)
print('IMPOSSIBLE')
