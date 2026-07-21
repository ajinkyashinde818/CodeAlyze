import numpy as np


n, m = map(int, input().split())
a = []
for i in range(n):
    a.append(list(input()[:]))
b = []
for i in range(m):
    b.append(list(input()[:]))
a = np.array(a)
b = np.array(b)
for i in range(n-m+1):
    for j in range(n-m+1):
        if (a[i:i+m, j:j+m] == b).all():
            print("Yes")
            break
    else:
        continue
    break
else:
    print("No")
