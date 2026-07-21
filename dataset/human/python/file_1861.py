import numpy as np
import sys

n,m = map(int, sys.stdin.readline().split())
a = np.array([list(input()) for _ in range(n)])
b = np.array([list(input()) for _ in range(m)])

flag = False

for i in range(n-m+1):
    for j in range(n-m+1):
        if (a[i:i+m,j:j+m] == b).all():
            flag = True
            break

print("Yes" if flag else "No")
