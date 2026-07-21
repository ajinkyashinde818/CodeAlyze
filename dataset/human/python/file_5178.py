n, m = list(map(int, input().split()))

E = {}
for i in range(m):
    a, b = list(map(int, input().split()))
    e = E.get(a, None)
    if e is None:
        e = []
    e.append(b)
    E[a] = e
    e = E.get(b, None)
    if e is None:
        e = []
    e.append(a)
    E[b] = e


def foo(E):
    for i in range(1, n):
        if i in E and 1 in E[i] and n in E[i]:
            return True
    return False

if foo(E):
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
