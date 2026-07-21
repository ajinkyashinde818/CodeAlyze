import sys
N,M = map(int,sys.stdin.readline().split())
start = []
goal = []
for i in range(M):
    a,b = map(int,sys.stdin.readline().split())
    if a == 1:
        start.append(b)
    if b == N:
        goal.append(a)
ans = 'IMPOSSIBLE'
seta = set(start)
setg = set(goal)
for i in seta:
    if i in setg:
        ans = 'POSSIBLE'
        break
print(ans)
