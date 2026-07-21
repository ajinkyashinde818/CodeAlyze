import sys
sys.setrecursionlimit(10**6)
n, k = map(int, input().split())
a = list(map(int, input().split()))

length = [-1] * n
path = [-1, []]
route = []


def func(now, depth):
    global path, length, a, route
    route.append(now)
    if length[now] == -1:
        length[now] = depth
        func(a[now]-1, depth+1)
    else:
        path = [length[now], route[length[now]:depth]]


func(0, 0)

if (k < path[0]):
    print(route[k] + 1)
else:
    tmp = k - path[0]
    tmp %= len(path[1])
    print(path[1][tmp] + 1)
