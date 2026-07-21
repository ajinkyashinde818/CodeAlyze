def solve(n, m, a, b):
    islands = set()

    for i in range(m):
        if(a[i] == 1):
            islands.add(b[i])
        if(b[i] == 1):
            islands.add(a[i])

    for i in range(m):
        if(a[i] == n and b[i] in islands):
            return "POSSIBLE"
        if(b[i] == n and a[i] in islands):
            return "POSSIBLE"
    return "IMPOSSIBLE"

(n, m) = map(int, input().split())
a = []
b = []

for i in range(m):
    (ai, bi) = map(int, input().split())
    a.append(ai)
    b.append(bi)

print(solve(n, m, a, b))
