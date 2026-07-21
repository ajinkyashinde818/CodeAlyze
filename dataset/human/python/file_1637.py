import numpy as np

def fn(a, b):
    for i in range(n-m+1):
        for j in range(n-m+1):
            if np.all(b == a[i:m+i,j:m+j]):
                return True
    return False

n, m = [int(i) for i in input().split()]
a = []
for i in range(n):
    res = []
    for j in input():
        if j == ".":
            res.append(1)
        elif j == "#":
            res.append(0)
    a.append(res)
b = []
for i in range(m):
    res = []
    for j in input():
        if j == ".":
            res.append(1)
        elif j == "#":
            res.append(0)
    b.append(res)

a = np.array(a)
b = np.array(b)

if fn(a, b):
    print("Yes")
else:
    print("No")
