import numpy as np
n, m = map(int, input().split())
a = np.array([list(input()) for _ in range(n)])
b = np.array([list(input()) for _ in range(m)])

for i in range(n-m+1):
    for j in range(n-m+1):
        flag = True
        for k in range(m):
            for l in range(m):
                if a[0+i+k, 0+j+l] != b[0+k, 0+l]:
                    flag = False
        if flag:
            break
    if flag:
        break
if flag:
    print('Yes')
else:
    print('No')
