import numpy as np


n, m = map(int,input().split())
a = np.array([list(input()) for i in range(n)])
b = np.array([list(input()) for i in range(m)])
flug = 0

for i in range(n-m+1):
    for j in range(n-m+1):
        if np.all(a[i:i+m, j:j+m] == b):
            flug =1

ans = 'Yes' if flug else 'No'
print(ans)
