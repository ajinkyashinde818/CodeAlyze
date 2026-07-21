from collections import defaultdict


def inpl():
    return list(map(int, input().split()))


N, K = inpl()
aa = inpl()

s = 1

route = [s]
ed = set([s])

for i in range(1, K + 1):
    s = aa[s - 1]
    if s in ed:
        Li = route.index(s)
        Ri = len(route)
        idx = Li + (K - Li) % (Ri - Li)
        print(route[idx])
        break
    else:
        route.append(s)
        ed.add(s)
        continue
else:
    print(s)
