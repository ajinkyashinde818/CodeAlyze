N, K = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

def getPath():
    curr = 1
    path = [curr]
    seen = {curr}
    while A[curr - 1] not in seen:
        curr = A[curr - 1]
        path.append(curr)
        seen.add(curr)
    assert A[curr - 1] in seen
    index = path.index(A[curr - 1])
    return path[:index], path[index:]

path, cycle = getPath()
if K + 1 < len(path) + len(cycle):
    print((path + cycle)[K])
else:
    print(cycle[(K - len(path)) % len(cycle)])
