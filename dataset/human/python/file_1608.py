import numpy as np

n, m = map(int, input().split())
a = np.array([list(input()) for _ in range(n)])
b = np.array([list(input()) for _ in range(m)])

ans = 'No'
for i in range(n-m+1):
    for j in range(n-m+1):
        if (a[i:m+i, j:m+j] == b).all():
            ans = 'Yes'
print(ans)
