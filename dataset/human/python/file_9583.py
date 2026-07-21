import sys
sys.setrecursionlimit(10 ** 5 * 2)
N, K = map(int, input().split())
A = [0] + list(map(int, input().split()))
top = -1
hist = []
finished = [True] + [False for _ in range(N)]
seen = [True] + [False for _ in range(N)]

def dfs(cur):
    global hist, finished, seen, top
    hist.append(cur)
    seen[cur] = True
    nex = A[cur]
    if seen[nex] and not finished[nex]:
        top = nex
        return
    dfs(nex)
    if not top == -1:
        return
    hist.pop()
    finished[cur] = True
    
dfs(1)
cycle = []
while not hist == []:
    i = hist.pop()
    cycle.append(i)
    if i == top:
        break

cycle.reverse()

cur = 1
while not cur == top and not K == 0:
    cur = A[cur]
    K -= 1

if cur == top:
    cur = cycle[K % len(cycle)]

print(cur)
