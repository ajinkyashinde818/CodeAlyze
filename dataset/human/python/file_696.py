import math
x1, y1, x2, y2 = [int(i) for i in input().split()]
n = int(input())

xy = [[x1, y1, 0]]
for _ in range(n):
    xy.append([int(i) for i in input().split()])
xy.append([x2, y2, 0])


def dif(x, y):
    return max(0, math.sqrt((x[0] - y[0]) ** 2 + (x[1] - y[1]) ** 2) - x[2] - y[2])




q = set([i for i in range(n + 2)])
mi = [10 ** 16] * (n + 2)
mi[0] = 0

while q:
    u = -1
    mm = 10**16
    for i in q:
        if mm > mi[i]:
            mm = mi[i]
            u = i
    
    q.remove(u)
    for i in q:
        mi[i] = min(mi[i], mi[u] + dif(xy[i], xy[u]))

print(mi[-1])
