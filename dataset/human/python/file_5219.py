import sys

N, M = map(int, sys.stdin.readline().strip().split())

paths = [[] for _ in range(N+1)]
for _ in range(M):
    a, b = map(int, sys.stdin.readline().strip().split())
    paths[a].append(b)
    paths[b].append(a)

for i in paths[1]:
    for j in paths[i]:
        if j == N:
            print("POSSIBLE")
            sys.exit()
print("IMPOSSIBLE")
