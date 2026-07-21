from sys import stdin
def input():
    return stdin.readline().strip()

n, m = map(int, input().split())
edge = [[] for _ in range(n)]
for _ in range(m):
    i, j = map(int, input().split())
    i -= 1
    j -= 1
    edge[i].append(j)
    edge[j].append(i)

for i in edge[0]:
    if n - 1 in edge[i]:
        print('POSSIBLE')
        exit()
else:
    print('IMPOSSIBLE')
