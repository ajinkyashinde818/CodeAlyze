import sys
from collections import deque

input = sys.stdin.readline
n, m = map(int, input().split())

E = [[] for i in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    E[a-1].append(b-1)
    E[b-1].append(a-1)

def bfs(cur, pre, d):
    stack = deque([[cur, pre, d]])
    while stack:
        cur, pre, d = stack.popleft()
        if cur == n-1:
            return True
        for e in E[cur]:
            if e != pre and d < 2:
                stack.append([e, cur, d+1])
    return False

if bfs(0, -1, 0):
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')
