import itertools

n, m = [int(_) for _ in input().split()]
a = []
b = []
for i in range(0, m):
    ai, bi = [int(_) for _ in input().split()]
    a.append(ai)
    b.append(bi)

first = [b[i] for i in range(0, m) if a[i] == 1]
second = [a[i] for i in range(0, m) if b[i] == n]

if set(first) & set(second):
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')
