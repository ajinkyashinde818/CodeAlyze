import math


def dfs(sc, i=0, qn=0, used=set()):
    if sc <= 0:
        return qn
    if i == d:
        i -= 1
        while i in used:
            i -= 1
        hanpa = math.ceil(sc / (100 * (i + 1)))
        if hanpa >= pc[i][0]:
            return inf
        return qn + hanpa
    p, c = pc[i]
    zenbu = (i + 1) * 100 * p + c
    used.add(i)
    re1 = dfs(sc - zenbu, i + 1, qn + p, used)
    used.remove(i)
    re2 = dfs(sc, i + 1, qn, used)
    return min(re1, re2)


inf = 10 ** 9
d, g = map(int, input().split())
pc = [list(map(int, input().split())) for _ in range(d)]
print(dfs(g))
