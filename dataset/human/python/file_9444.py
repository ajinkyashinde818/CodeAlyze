n, k = map(int, input().split())
a = list(map(int, input().split()))
g = dict()

for i, v in enumerate(a):
    g[i+1] = v

def find_num(target):
    path = 1
    target_ = g[target]
    while target_ != target:
        target_ = g[target_]
        path += 1
    return path

target = 1
visited = dict()
flag = False
for i in range(k):
    target = g[target]
    if target not in visited:
        visited[target] = True
    else:
        p = find_num(target)
        flag = True
        break
if flag:
    for _ in range((k-1-i)%p):
        target = g[target]
    print(target)
else:
    print(target)
