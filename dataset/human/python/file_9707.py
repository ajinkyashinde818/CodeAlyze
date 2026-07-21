import sys
sys.setrecursionlimit(10**6)
n,k = map(int, input().split())
a = list(map(int, input().split()))
adjacent_list = [[] for i in range(n+1)]
for i in range(n):
    adjacent_list[i+1].append(a[i])
finished = set()
route = []
def dfs(node):
    finished.add(node)
    route.append(node)
    for i in adjacent_list[node]:
        if i not in finished:
            dfs(i)
dfs(1)
if len(route) > k:
    print(route[k])
else:
    index = route.index(adjacent_list[route[-1]][0])
    k -= index
    route = route[index:]
    print(route[k % len(route)])
