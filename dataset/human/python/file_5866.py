from itertools import tee


def pairwise(iterable):
    x, y = tee(iterable)
    next(y, None)
    return zip(x, y)


n = int(input())
a = tuple(map(int, input().split(" ")))
b = tuple(map(int, input().split(" ")))
c = tuple(map(int, input().split(" ")))

point = sum(b)
for i, j in pairwise(a):
    if j == i + 1:
        point += c[i - 1]

print(point)
