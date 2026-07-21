import numpy as np
n, m = map(int, input().split())
a = []
for _ in range(n):
    a.append(list(input()))
a = np.array(a)
b = []
for _ in range(m):
    b.append(list(input()))
b = np.array(b)
for dy in range(n-m+1):
    for dx in range(n-m+1):
        if (a[dy:m+dy, dx:m+dx]==b).all():
            print('Yes')
            break
    else:
        continue
    break
else:
    print('No')
