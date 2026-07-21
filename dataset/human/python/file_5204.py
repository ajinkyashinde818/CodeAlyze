import sys
import copy

N,M = map(int, input().split())

def dfs(node, count):

    if seen[node]==True:
        return
    seen[node]=True

    if node==(N-1) and count==2:
        print("POSSIBLE")
        sys.exit()
    elif count==2:
        return
    count = count + 1
    seen[node]=True

    for next_node in V[node]:
        dfs(next_node, count)

    return

V = []
seen = [False]*N

for i in range(N):
    V.append(set())

for i in range(M):
    *l, = map(int, input().split())
    V[l[0]-1].add(l[1]-1)
    V[l[1]-1].add(l[0]-1)


dfs(0, 0)

print("IMPOSSIBLE")
