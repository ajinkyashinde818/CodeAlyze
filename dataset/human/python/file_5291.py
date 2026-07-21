def answer(destination, services):
    P, M = ("POSSIBLE", "IMPOSSIBLE")
    dic = {}
    for a, b in services:
        if dic.get(a) is None:
            dic[a] = [b]
        else:
            dic[a].append(b)
        if dic.get(b) is None:
            dic[b] = [a]
        else:
            dic[b].append(a)
    if dic.get(destination) is None: return M
    arr = dic[destination]
    for i in arr:
        if 1 in dic[i]:
            return P
    return M

n, m = map(int, input().split())
services = []
for _ in range(m):
    a, b = map(int, input().split())
    services.append((a, b))
print(answer(n, services))
