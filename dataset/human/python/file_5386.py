from collections import deque
N, M = map(int, input().split())
E = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    E[a-1].append(b)
    E[b-1].append(a)
print("POSSIBLE")if any(N in E[v-1] for v in E[0]) else print("IMPOSSIBLE")
