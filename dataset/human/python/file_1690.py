import numpy as np
n, m = map(int, input().split())
a = np.zeros((n, n))
b = np.zeros((m, m))
for i in range(n):
    for j, s in enumerate(input()):
        if s == "#": a[i][j] = 1
for i in range(m):
    for j, s in enumerate(input()):
        if s == "#": b[i][j] = 1
for i in range(n - m + 1):
    for j in range(n - m + 1):
        sa = a[i:i+m, j:j+m]
        if not np.sum(np.logical_xor(sa, b)):
            print("Yes")
            exit()
print("No")
